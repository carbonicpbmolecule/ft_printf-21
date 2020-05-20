/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:01:20 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/18 13:01:22 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			arg_type(char c)
{
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
	else if (c == 'i')
		return (I);
	return (0);
}

static int			arg_size(const char *format)
{
	size_t size;

	size = 0;
	while (size < ft_strlen(format))
	{
		if (format[size] == '%' && size != 0)
			return (0);
		if (ft_strchr(TYPES, format[size]))
			return (size + 1);
		size++;
	}
	return (0);
}

static int			arg_afterpoint(t_argument *arg, const char *format)
{
	int		offset;
	char	*delimiter;

	delimiter = ft_strnchr(format, '.', arg->size - 2);
	if (delimiter)
		offset = ft_strlen(format) - ft_strlen(delimiter);
	else
		return (arg->type == F ? 6 : 0);
	offset = ft_atoi(format + offset + 1);
	return (offset ? offset : -1);
}

t_argument			*arg_parse(const char *format)
{
	int				flags_offset;
	t_argument		*arg;

	arg = (t_argument *)malloc(sizeof(t_argument));
	arg->size = arg_size(format);
	if (!arg->size)
	{
		ft_memdel((void **)&arg);
		return (0);
	}
	arg->type = arg_type(*(format + arg->size - 1));
	arg->afterpoint = arg_afterpoint(arg, format);
	arg->field_filling = ' ';
	arg->alignment = RIGHT;
	arg->sign_display = 0;
	arg->data = 0;
	arg->special = ft_memalloc(3);
	flags_offset = parse_flags(format, arg);
	arg->field_size = ft_atoi(format + 1 + flags_offset);
	arg->modificator = parse_modificator(arg, format);
	if ((arg->type == XS || arg->type == XL) && arg->afterpoint == -1)
		ft_bzero(arg->special, 3);
	return (arg);
}
