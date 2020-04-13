#include "../inc/ft_printf.h"

static int			arg_is_valid_type(char c) {
	if (c == 'f' || c == 's' || c == 'p' || c == 'c')
		return 1;
	return 0;
}

static int			arg_type(char c) {
	if (c == 'f')
		return D;
	return 0;
}

static int			arg_size(const char *format) {
	int i = 0;

	while (*format) {
		if (arg_is_valid_type(*format))
			return i+1;
		i++;
		format++;
	}
	return 0;
}

static int			arg_spaces(const char *format, int delimiter, int len) {
	int i = 1;
	int spaces = 0;
	if (!delimiter)
		delimiter = len - 1;
	while (i < delimiter) {
		if (ft_isdigit(format[i]))
			spaces = spaces * 10 + (format[i] - '0');
		else
			return 0;
		i++;
	}
	return spaces;
}

static int			arg_afterpoint(const char *format, int delimiter) {
	int afterpoint = 0;
	int i = 0;
	if (!delimiter)
		return 6;
	i = delimiter + 1;
	while (!arg_is_valid_type(format[i])) {
		if (ft_isdigit(format[i]))
			afterpoint = afterpoint * 10 + (format[i] - '0');
		else
			return 0;
		i++; 
	}
	return afterpoint;
}

static int		arg_delimiter_pos(const char *format, int len) {
	int i = 0;

	while (i < len) {
		if (format[i] == '.') {
			return i;
		}
		i++;
	}
	return 0;
}

argument	arg_parse(const char *format) {
	argument		arg;

	arg.size = arg_size(format);
	arg.delimiter = arg_delimiter_pos(format, arg.size);
	arg.spaces = arg_spaces(format, arg.delimiter, arg.size);
	arg.afterpoint = arg_afterpoint(format, arg.delimiter);
	arg.type = arg_type(*(format + arg.size - 1));

	return arg;
}