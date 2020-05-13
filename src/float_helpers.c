/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 13:48:44 by jirwin            #+#    #+#             */
/*   Updated: 2020/05/13 18:25:40 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		getsize(unsigned long n)
{
	int size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	long_nbzero(unsigned short *n, unsigned short len)
{
	int i;

	i = 0;
	while (i < len)
		n[i++] = 0;
}

void	long_nbcopy(unsigned short *dest, unsigned short *src)
{
	int i;
	int j;

	j = 1;
	i = 1;
	dest[0] = src[0];
	while (j <= dest[0])
		dest[i++] = src[j++];
}
