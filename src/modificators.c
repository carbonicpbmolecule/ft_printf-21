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

int	valid_modificator(const char *str)
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
