/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:01:10 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/18 13:01:12 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		add_flags(argument *arg)
{
	char	*formated;
	char	*tmp;
	char	*data;
	size_t	size;

	data = arg->data;
	size = ft_strlen(data);
	if (!size || arg->size < 3)
		return ;
	formated = (char *)malloc(size + 3);
	if (arg->type <= D && arg->data[0] != '-' && arg->field_filling != '0')
		formated[0] = arg->sign_display;
	ft_strlcat(formated, arg->special, arg->data ? size + 3: 0);
	ft_strlcat(formated, data, size + 3);
	tmp = arg->data;
	arg->data = formated;
	free(tmp);
}

static size_t	arg_print(argument *arg)
{
	int		filling_size;
	size_t	printed;
	size_t	data_len;

	add_flags(arg);
	data_len = ft_strlen(arg->data);
	filling_size = arg->field_size - data_len;
	printed = 0;
	if (arg->alignment == LEFT)
		printed += cputstr(arg->data);
	if (arg->alignment == RIGHT && arg->field_filling == '0' && \
															arg->sign_display)
		printed += cputchar('+' + 0 * filling_size--);
	while (filling_size-- > 0)
		printed += cputchar(arg->field_filling);
	if (arg->alignment == RIGHT)
		printed += cputstr(arg->data);
	return (printed);
}

static void		arg_free(argument *arg)
{
	ft_strdel(&(arg->special));
	ft_strdel(&(arg->data));
	ft_strdel(&(arg->modificator));
	ft_memdel((void **)&arg);
}

static size_t	define_arg(va_list *args, argument *arg)
{
	if (arg->type >= F && arg->type <= U)
		handle_number(arg, args);
	else if (arg->type == C || arg->type == S)
		handle_chars(arg, args);
	else if (arg->type == P)
		arg->data = ft_ptoa(va_arg(*args, unsigned long int));
	return (arg_print(arg));
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	argument	*arg;
	size_t		printed;

	va_start(args, format);
	printed = 0;
	while (*format)
		if (*format == '%' && (arg = arg_parse(format)))
		{
			printed += define_arg(&args, arg);
			format += arg->size;
			arg_free(arg);
		}
		else
			format += handle_invalid(format, &printed);
	va_end(args);
	return (printed);
}
