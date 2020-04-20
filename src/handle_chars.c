/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:01:15 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/18 13:01:17 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*handle_char(argument *arg, va_list *args)
{
	char	*data;
	char	c;

	c = (char)va_arg(*args, int);
	if (!c)
		return (0);
	data = ft_strnew(2);
	data[0] = c;
	arg->field_filling = ' ';
	return (data);
}

static char		*handle_string(argument *arg, va_list *args)
{
	char *data;
	char *res;

	data = va_arg(*args, char*);
	if (arg->afterpoint > 0 && data)
	{
		res = ft_strsub(data, 0, arg->afterpoint);
		arg->field_filling = ' ';
	}
	else if (arg->afterpoint <= 0 && data)
		res = ft_strdup(data);
	else
	{
		res = ft_strdup("(none)");
		arg->field_size = 0;
	}
	return (res);
}

void			handle_chars(argument *arg, va_list *args)
{
	if (arg->type == C)
		arg->data = handle_char(arg, args);
	else if (arg->type == S)
		arg->data = handle_string(arg, args);
}
