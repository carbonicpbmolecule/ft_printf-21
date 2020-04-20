/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:01:17 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/18 16:16:00 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#define MODIFICATORS_LEN 5

const char g_modificators[4][3] = {"hh", "h", "ll", "l"};

static int	valid_modificator(char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (i < MODIFICATORS_LEN && g_modificators[i])
	{
		if (ft_strcmp(g_modificators[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

int			is_valid_modificator(char mod)
{
	if (ft_isdigit(mod) || ft_strchr(MODS, mod))
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
	while (is_valid_modificator(*format))
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

	skipped = 0;
	if (*format == '%')
		skipped = handle_percent(format, printed);
	if (!skipped)
	{
		*printed += cputchar(*format);
		skipped++;
	}
	return (skipped);
}

char		*parse_modificator(argument *arg, const char *format)
{
	char	*mod;

	if (arg->size < 3)
		return (0);
	mod = ft_strsub(format, arg->size - 3, 2);
	if (valid_modificator(mod))
		return (mod);
	free(mod);
	mod = ft_strsub(format, arg->size - 2, 1);
	if (valid_modificator(mod))
		return (mod);
	free(mod);
	return (0);
}
