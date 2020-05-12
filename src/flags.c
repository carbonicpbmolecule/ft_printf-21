/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:00:55 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/18 13:01:00 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_special_chars(char *prefix, int type)
{
	if (type == XS || type == P)
		ft_strcpy(prefix, "0x");
	else if (type == XL)
		ft_strcpy(prefix, "0X");
	else if (type == O)
		ft_strcpy(prefix, "0");
	else if (type == F)
		ft_strcpy(prefix, ".");
}

int				parse_flags(const char *format, t_argument *arg)
{
	int	i;

	i = 0;
	if (*format == '%')
		format++;
	while (i < arg->size)
	{
		if (!ft_strchr("#0-+ ", format[i]))
			break ;
		if ((format[i] == '#' || arg->type == P))
			get_special_chars(arg->special, arg->type);
		if (format[i] == '0' && arg->type <= P)
			arg->field_filling = arg->alignment == RIGHT ? '0' : ' ';
		if (format[i] == '-')
		{
			arg->alignment = LEFT;
			arg->field_filling = ' ';
		}
		if (format[i] == ' ' && arg->type <= D)
			arg->sign_display = arg->sign_display ? arg->sign_display : ' ';
		if (format[i] == '+' && arg->type <= D)
			arg->sign_display = '+';
		i++;
	}
	return (i);
}
