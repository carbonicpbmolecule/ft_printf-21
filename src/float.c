/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:20:49 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/22 17:20:50 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_overflow(unsigned short *part1, unsigned short *part2, int flag)
{
	double			n2;
	int				n1_int;
	int				n1_int_size;
	int				result;
	int 			i;

	if (!flag)
	{
		i = part1[0];
		n1_int_size = i - 8;
		while (i > n1_int_size && i > 0)
		{
			n1_int = n1_int * 10 + part1[i--];
			n1_int_size = i;
		}
	}
	n2 = (part2[part2[0]] * 1.0) + (part2[part2[0] - 1] * 0.1) + (part2[part2[0] - 2] * 0.01) + (part2[part2[0] - 3] * 0.001);
	result = n1_int * n2;
	if (getsize(n1_int) < getsize(result))
		return (1);
	return (0);
}

char 			*ft_ftoa(double n, int afterpoint) {
	binary64		d;
	unsigned short 	*part1;
	unsigned short	*part2;
	unsigned short 	*result;
	char 			*final;
	double			power;
	int				point;
	int				flag;

	d.d = n;
	point = 0;
	flag = d.parts.exponent < 1023;
	if (flag)
	{
		power = ft_power(2, d.parts.exponent - 1023);
		part1 = write_double(power, 0);
	}
	else
		part1 = pow_nb(2, d.parts.exponent - 1023);
	part2 = write_double(d.parts.mantissa / ft_power(2, 52), 1);
	point = flag ? 2 : part1[0] + 1 + check_overflow(part1, part2, flag);
	result = mult_nb(part1, part2);
	final = round_nb(result, point, afterpoint, d.parts.sign);
	return (final);
}