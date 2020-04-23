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

#include "../inc/ft_printf.h"

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

static int			arg_field_size(const char *format, int delimiter, int len)
{
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

static int			arg_afterpoint(argument *arg, const char *format)
{
	int		afterpoint;
	char	*delimiter;
	int		i;

	afterpoint = 0;
	delimiter = ft_strnchr(format, '.', arg->size - 2);
	if (delimiter)
		arg->delimiter = ft_strlen(format) - ft_strlen(delimiter);
	else
		return (arg->type == F ? 6 : 0);
	i = arg->delimiter + 1;
	while (!ft_strchr(TYPES, format[i]))
	{
		if (ft_isdigit(format[i]))
			afterpoint = afterpoint * 10 + (format[i] - '0');
		else
			return (0);
		i++;
	}
	if (!afterpoint)
		return (-1);
	return (afterpoint);
}

argument			*arg_parse(const char *format)
{
	int				flags_offset;
	argument		*arg;

	arg = (argument *)malloc(sizeof(argument));
	arg->size = arg_size(format);
	if (!arg->size)
		return (0);
	arg->type = arg_type(*(format + arg->size - 1));
	arg->afterpoint = arg_afterpoint(arg, format);
	arg->field_filling = ' ';
	arg->alignment = RIGHT;
	arg->sign_display = 0;
	arg->data = 0;
	arg->special = ft_memalloc(2);
	flags_offset = parse_flags(format, arg);
	arg->field_size = arg_field_size(format + flags_offset + 1, arg->delimiter \
			- flags_offset - 1, arg->size - flags_offset);
	arg->modificator = parse_modificator(arg, format);
	return (arg);
}
