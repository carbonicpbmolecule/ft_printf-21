#include "../inc/ft_printf.h"
#include <wchar.h>

static char		*handle_unsigned(argument *arg, va_list *args)
{
	int		base;
	int		lcase;
	char	*mod;

	mod = arg->modificator;
	lcase = arg->type == XS ? 0 : 1;
	if (arg->type == XS || arg->type == XL)
		base = 16;
	else if (arg->type == O)
		base = 8;
	else
		base = 10;
	if (ft_strequ(mod, "hh"))
    	return (ft_ltoa_base((unsigned char)va_arg(*args, unsigned long int),\
															base, lcase));
	else if (ft_strequ(mod, "h"))
		return (ft_ltoa_base((unsigned short int)va_arg(*args, unsigned int),\
															base, lcase));
	else if (ft_strequ(mod, "ll"))
		return (ft_ltoa_base((unsigned long long) va_arg(*args, \
										unsigned long long), base, lcase));
	else if (ft_strequ(mod, "l"))
		return (ft_ltoa_base((unsigned long)va_arg(*args,\
												unsigned int), base, lcase));
	else
		return (ft_ltoa_base(va_arg(*args, unsigned int), base, lcase));
}

static char		*handle_signed(argument *arg, va_list *args)
{
	char	*mod;

	mod = arg->modificator;
	if (ft_strequ(mod, "hh"))
    	return (ft_itoa_base((signed char)va_arg(*args, signed int), 10, 0));
	else if (ft_strequ(mod, "h"))
		return (ft_itoa_base((signed short int)va_arg(*args, signed int), \
																		10, 0));
	else if (ft_strequ(mod, "ll"))
		return (ft_itoa_base((signed long long int)va_arg(*args, \
												signed long long int), 10 , 0));
	else if (ft_strequ(mod, "l"))
		return (ft_itoa_base((signed long int) va_arg(*args, signed long int), \
																		10, 0));
	else
		return (ft_itoa_base(va_arg(*args, signed int), 10 , 0));
}

void			handle_number(argument *arg, va_list *args)
{
    if (arg->type == F)
		arg->data = ft_ftoa(va_arg(*args, double), arg->afterpoint);
	else if (arg->type >= XS && arg->type <= U)
		arg->data = handle_unsigned(arg, args);
	else if (arg->type == D || arg->type == I)
		arg->data = handle_signed(arg, args);
}