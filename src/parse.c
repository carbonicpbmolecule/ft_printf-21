#include "../inc/ft_printf.h"

static int			arg_type(char c) {
	if (c == 'f')
		return (F);
	else if (c == 'x')
		return (XS);
	else if (c == 'X')
		return (XL);
	else if (c == 'o')
		return (O);
	else if (c == 'c')
		return (C);
	else if (c == 'u')
		return (U);
	else if (c == 's')
		return (S);
	else if (c == 'p')
		return (P);
	else if (c == 'd')
		return (D);
	else if (c == 'i');
		return (I);	
	return (0);
}

static int			arg_size(const char *format) {
	size_t size;
	
	size = 0;
	while (size < ft_strlen(format))
	{	
		if (ft_strchr(TYPES, format[size]))
			return (size + 1);	
		size++;
	}
	return (0);
}

static int			arg_field_size(const char *format, int delimiter, int len) {
	int i;
	int spaces;

	i = 0;
	spaces = 0;
	if (delimiter < 1)
		delimiter = len - 2;
	
	while (i < delimiter)
	{
		if (ft_isdigit(format[i]))
			spaces = spaces * 10 + (format[i] - '0');
		else
			return (0);
		i++;
	}
	return (spaces);
}

static int			arg_afterpoint(const char *format, int delimiter) {
	int		afterpoint;
	int 	i;

	afterpoint = 0;
	i = 0;
	if (!delimiter)
		return (6);
	i = delimiter + 1;
	while (!ft_strchr(TYPES, format[i])) {
		if (ft_isdigit(format[i]))
			afterpoint = afterpoint * 10 + (format[i] - '0');
		else
			return (0);
		i++; 
	}
	return (afterpoint);
}

static int			arg_delimiter_pos(const char *format, int len) {
	int		i;
	
	i = 0;
	while (i < len) {
		if (format[i] == '.') {
			return (i);
		}
		i++;
	}
	return (0);
}

argument		*arg_parse(const char *format) {
	int				flags_offset;
	argument		*arg;

	arg = (argument *) malloc(sizeof(argument));
	arg->size = arg_size(format);
	if (!arg->size)
		return (0);
	arg->delimiter = arg_delimiter_pos(format, arg->size);
	arg->afterpoint = arg_afterpoint(format, arg->delimiter);
	arg->type = arg_type(*(format + arg->size - 1));
	arg->field_filling = ' ';
	arg->alignment = RIGHT;
	arg->sign_display = 0;
	arg->special = (char *)malloc(2);
	
	flags_offset = parse_flags(format, arg);
	arg->field_size = arg_field_size(format + flags_offset + 1, arg->delimiter \
			- flags_offset - 1, arg->size - flags_offset);
	arg->modificator = parse_modificator(arg, format);
	// test_parse_flags(arg);
	// test_parse(arg);
	return (arg);
}