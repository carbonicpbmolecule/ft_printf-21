#include "../inc/ft_printf.h"

static char *add_flags(argument arg, char *data)
{
	char	*formated;
	size_t	size;

	size = ft_strlen(data);
	if (!size || arg.size < 3)
		return 0;
	formated = (char *)malloc(size + 3);
	if (arg.type <= D && arg.data[0] != '-' && arg.field_filling != '0')
		formated[0] = arg.sign_display;
	ft_strlcat(formated, arg.special, size + 3);
	ft_strlcat(formated, data, size + 3);
	free(data);
	return formated;
}

static void arg_print(argument arg) {
	int filling_size;
	int special_size;

	arg.data = add_flags(arg, arg.data);
	filling_size = arg.field_size - ft_strlen(arg.data);
	if (arg.alignment == LEFT)
		ft_putstr(arg.data);
	if (arg.alignment == RIGHT && arg.field_filling == '0')
		ft_putchar('+' + 0 * filling_size--);
	while (filling_size-- > 0)
		ft_putchar(arg.field_filling);

	if (arg.alignment == RIGHT)
		ft_putstr(arg.data);
}

int ft_printf(const char *format, ...)
{
	va_list		args;
	argument	arg;

	va_start(args, format);

	while (*format) {
		if (*format == '%') {
			arg = arg_parse(format); // <- spaces, afterpoint, type, size;
			if (arg.type == F)
				arg.data = ft_ftoa(va_arg(args, double), arg.afterpoint);
			arg_print(arg);
			format += arg.size;
		}
		ft_putchar(*(format++));
	}

	va_end(args);
}
