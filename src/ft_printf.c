#include "../inc/ft_printf.h"

static void 	add_flags(argument *arg)
{
	char	*formated;
	char 	*tmp;
	char	*data;
	size_t	size;

	data = arg->data;
	size = ft_strlen(data);
	if (!size || arg->size < 3)
		return ;
	formated = (char *)malloc(size + 3);
	if (arg->type <= D && arg->data[0] != '-' && arg->field_filling != '0')
		formated[0] = arg->sign_display;
	ft_strlcat(formated, arg->special, size + 3);
	ft_strlcat(formated, data, size + 3);
	tmp = arg->data;
	arg->data = formated;
	free(tmp);
}

static void 	arg_print(argument *arg) {
	int filling_size;
	int special_size;

	add_flags(arg);
	filling_size = arg->field_size - ft_strlen(arg->data);
	if (arg->alignment == LEFT)
		ft_putstr(arg->data);
	if (arg->alignment == RIGHT && arg->field_filling == '0' && \
															arg->sign_display)
		ft_putchar('+' + 0 * filling_size--);
	while (filling_size-- > 0)
		ft_putchar(arg->field_filling);
	if (arg->alignment == RIGHT)
		ft_putstr(arg->data);
}

void 			arg_free(argument *arg)
{
	if (arg->special)
		free(arg->special);
	if (arg->data)
		free(arg->data);
	if (arg)
		free(arg);
}

void	define_arg(va_list *args, argument *arg, const char *format)
{
	if (arg->type == F)
		arg->data = ft_ftoa(va_arg(*args, double), arg->afterpoint);
	else if (arg->type == XS || arg->type == XL)
		arg->data = ft_itoa_base(va_arg(*args, unsigned int), 16, arg->type == \
																XL ? 1 : 0);
	else if (arg->type == O)
		arg->data = ft_itoa_base(va_arg(*args, unsigned int), 8, 0);
	arg_print(arg);
}

int 			ft_printf(const char *format, ...)
{
	va_list		args;
	argument	*arg;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && (arg = arg_parse(format)))
		{
			define_arg(&args, arg, format);
			format += arg->size;
			arg_free(arg);
		}
		ft_putchar(*(format++));
	}
	va_end(args);
}
