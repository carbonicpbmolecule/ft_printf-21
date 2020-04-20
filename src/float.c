/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:01:01 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/18 13:01:02 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int			int_to_str(long int x, char *str, int d, int sign)
{
	int i;

	i = 0;
	if (x == 0)
		str[i++] = '0';
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x /= 10;
	}
	while (i < d)
		str[i++] = '0';
	if (sign)
		str[i++] = '-';
	ft_strrev(str, i);
	str[i] = '\0';
	return (i);
}

static double		ft_round(double f, int afterpoint)
{
	double	div;

	div = ft_pow(10, afterpoint);
	f *= div;
	f += 0.5;
	return (f / div);
}

char				*ft_ftoa(double n, int afterpoint)
{
	char		*r;
	int			i;
	long int	ipart;
	int			sign;
	double		fpart;

	n = ft_round(n, afterpoint);
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	ipart = (long int)n;
	fpart = n - (double)ipart;
	r = (char *)malloc(sizeof(char) * \
			(ft_get_nb_size(ipart) + afterpoint + 2 + sign));
	i = int_to_str(ipart, r, 0, sign);
	if (afterpoint != 0)
	{
		r[i] = '.';
		fpart *= ft_pow(10, afterpoint);
		int_to_str((long int)fpart, r + i + 1, afterpoint, 0);
	}
	return (r);
}
