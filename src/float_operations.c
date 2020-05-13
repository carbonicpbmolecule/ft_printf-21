/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 18:22:50 by jirwin            #+#    #+#             */
/*   Updated: 2020/05/13 18:23:16 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned short			*long_pow(unsigned int nb, int power)
{
	unsigned short *a;
	unsigned short *tmp;
	unsigned short *result;

	result = long_write_long_int(1);
	if (power == 0)
		return (result);
	a = long_write_long_int(nb);
	while (power--)
	{
		tmp = long_mult(result, a);
		free(result);
		result = tmp;
	}
	free(a);
	return (result);
}

static unsigned short	*long_mult_alloc(unsigned short *a, unsigned short *b)
{
	unsigned short rlen;
	unsigned short *result;

	rlen = a[0] + b[0] + 1;
	result = (unsigned short int *)malloc(sizeof(unsigned short int) * rlen);
	if (!result)
		exit(1);
	long_nbzero(result, rlen);
	return (result);
}

static void				checkremainder(unsigned short *a, \
										unsigned short *remainder, int *k)
{
	while (*remainder)
	{
		*remainder += a[*k];
		a[*k] = *remainder % 10;
		*remainder /= 10;
		(*k > a[0]) ? a[0] = *k++ : *k++;
	}
}

unsigned short			*long_mult(unsigned short *a, unsigned short *b)
{
	unsigned short	*result;
	unsigned short	remainder;
	int				k;
	int				i;
	int				j;

	result = long_mult_alloc(a, b);
	i = 0;
	while (++i <= a[0])
	{
		j = 0;
		while (++j <= b[0])
		{
			remainder = a[i] * b[j];
			k = i + j - 1;
			result[0] = (remainder == 0) ? k++ : result[0];
			checkremainder(result, &remainder, &k);
		}
	}
	return (result);
}

unsigned short			*long_add(unsigned short *a, \
									unsigned short *b, int *point)
{
	int max;
	int c;
	int kd;
	int i;

	max = (a[0] > b[0]) ? a[0] : b[0];
	c = 0;
	kd = 0;
	i = 1;
	while (i <= max)
	{
		kd = (i > b[0]) ? 0 : b[i];
		c = c + a[i] + kd;
		a[i++] = c % 10;
		c = c / 10;
	}
	if (c > 0)
	{
		max = max + 1;
		*point = *point + 1;
		a[max] = c;
	}
	a[0] = max;
	return (a);
}
