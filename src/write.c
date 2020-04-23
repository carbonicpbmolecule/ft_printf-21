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
	write(1, &c, 1);
	return (1);
}

int		cputstr(const char *str)
{
	if (!str)
		return (0);

	ft_putstr(str);
	return(ft_strlen(str));
}
