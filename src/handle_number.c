/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:50:47 by jirwin            #+#    #+#             */
/*   Updated: 2020/05/15 14:32:08 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

static char		*handle_unsigned(t_argument *arg, va_list *args)
{
	int		base;
	int		lcase;

	lcase = arg->type == XS ? 0 : 1;
	base = 10;
	if (arg->type == XS || arg->type == XL)
		base = 16;
	else if (arg->type == O)
		base = 8;
	if (ft_strequ(arg->modificator, "hh"))
		return (ft_ltoa_base((unsigned char)va_arg(*args, unsigned long int),\
															base, lcase));
	else if (ft_strequ(arg->modificator, "h"))
		return (ft_ltoa_base((unsigned short int)va_arg(*args, unsigned int),\
															base, lcase));
	else if (ft_strequ(arg->modificator, "ll"))
		return (ft_ltoa_base((unsigned long long)va_arg(*args, \
										unsigned long long), base, lcase));
	else if (ft_strequ(arg->modificator, "l"))
		return (ft_ltoa_base((unsigned long)va_arg(*args,\
												unsigned long), base, lcase));
	else
		return (ft_ltoa_base(va_arg(*args, unsigned int), base, lcase));
}

static char		*handle_signed(t_argument *arg, va_list *args)
{
	char	*mod;

	mod = arg->modificator;
	if (ft_strequ(mod, "hh"))
		return (ft_itoa_base((signed char)va_arg(*args, signed int), 10, 0));
	else if (ft_strequ(mod, "h"))
		return (ft_itoa_base((signed short int)va_arg(*args, signed int),\
																		10, 0));
	else if (ft_strequ(mod, "ll"))
		return (ft_itoa_base((signed long long int)va_arg(*args,\
												signed long long int), 10, 0));
	else if (ft_strequ(mod, "l"))
		return (ft_itoa_base((signed long int)va_arg(*args, signed long int),\
																		10, 0));
	else
		return (ft_itoa_base(va_arg(*args, signed int), 10, 0));
}

static char		*handle_float(t_argument *arg, va_list *args)
{
	if (arg->type == F && ft_strequ(arg->modificator, "L"))
		return (lftoa(va_arg(*args, long double), arg->afterpoint,\
																arg->special));
	else
		return (ftoa(va_arg(*args, double), arg->afterpoint, arg->special));
}

void			handle_number(t_argument *arg, va_list *args)
{
	char *tmp;

	if (arg->type == F)
		arg->data = handle_float(arg, args);
	else if (arg->type >= XS && arg->type <= U)
		arg->data = handle_unsigned(arg, args);
	else if (arg->type == D || arg->type == I)
		arg->data = handle_signed(arg, args);
	if (ft_strequ(arg->data, "0") && arg->afterpoint >= 0)
		arg->special[0] = '\0';
	if (arg->data[0] == '-')
	{
		tmp = ft_strsub(arg->data, 1, ft_strlen(arg->data));
		ft_strdel(&(arg->data));
		arg->data = tmp;
		arg->sign_display = '-';
	}
}
