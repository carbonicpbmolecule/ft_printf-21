#include "../inc/ft_printf.h"

static void arg_print(argument arg) {
	int spaces = 0;

	if (ft_strlen(arg.data) < arg.spaces)
		spaces = arg.spaces - ft_strlen(arg.data);
	while (spaces--)
		ft_putchar(' ');
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
			if (arg.type == D)
				arg.data = ft_ftoa(va_arg(args, double), arg.afterpoint);
			arg_print(arg);
			format += arg.size;
		}
		ft_putchar(*(format++));
	}

	va_end(args);
}
