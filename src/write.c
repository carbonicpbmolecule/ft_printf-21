/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:21:21 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/22 17:21:39 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		cputchar(char c)
{
	if (c)
		write(1, &c, 1);
	return (c ? 1 : 0);
}

int		cputstr(const char *str)
{
	if (!str)
		return (0);
	if (str && *str)
	{
		ft_putstr(str);
		return(ft_strlen(str));
	}
	return (0);
}
