/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:30:19 by jirwin            #+#    #+#             */
/*   Updated: 2020/05/15 11:30:20 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned short			*long_pow(unsigned int nb, int power)
{
	unsigned short *a;
	unsigned short *tmp;
	unsigned short *result;

	result = long_write_lint(1);
	if (power == 0)
		return (result);
	a = long_write_lint(nb);
	while (power--)
	{
		tmp = long_mult(result, a);
		free(result);
		result = tmp;
	}
	free(a);
	return (result);
}

static unsigned short	*mult(unsigned short *dest, unsigned short *a, \
															unsigned short *b)
{
	int				i;
	int				j;
	unsigned int	cr;
	unsigned int	k;

	i = 0;
	while (++i <= a[0])
	{
		j = 0;
		while (++j <= b[0])
		{
			cr = a[i] * b[j];
			k = i + j - 1;
			dest[0] = !cr ? k++ : dest[0];
			while (cr)
			{
				cr = cr + dest[k];
				dest[k] = cr % 10;
				cr /= 10;
				(k > dest[0]) ? dest[0] = k++ : k++;
			}
		}
	}
	return (dest);
}

unsigned short			*long_mult(unsigned short *a, unsigned short *b)
{
	unsigned short rlen;
	unsigned short *result;

	rlen = a[0] + b[0] + 1;
	result = (unsigned short int *)malloc(sizeof(unsigned short int) * rlen);
	if (!result)
		exit(1);
	long_nbzero(result, rlen);
	return (mult(result, a, b));
}

unsigned short			*long_add(unsigned short *a, unsigned short *b, \
																int *point)
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
		a[i] = c % 10;
		c = c / 10;
		i++;
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
