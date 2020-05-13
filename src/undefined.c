/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:12:48 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/29 20:14:03 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_valid_modificator(char mod)
{
	if (ft_isdigit(mod) || ft_strchr(FLAGS, mod))
		return (1);
	return (0);
}

int			handle_percent(const char *format, size_t *printed)
{
	int	skipped;

	skipped = 0;
	if (!format || !*format)
		return (0);
	format += 1;
	while (*format && is_valid_modificator(*format))
	{
		skipped++;
		format++;
	}
	if (*format == '%')
	{
		*printed += cputchar('%');
		skipped++;
	}
	if (!skipped)
		return (0);
	return (skipped + 1);
}

int			handle_invalid(const char *format, size_t *printed)
{
	size_t	skipped;
	char	*tmp;

	skipped = 0;
	if (*format == '%')
	{
		tmp = ft_strtrim(format);
		if (ft_strlen(tmp) == 1)
		{
			ft_strdel(&tmp);
			return (1);
		}
		ft_strdel(&tmp);
		skipped = handle_percent(format, printed);
	}
	if (!skipped)
	{
		*printed += cputchar(*format);
		skipped++;
	}
	return (skipped);
}
