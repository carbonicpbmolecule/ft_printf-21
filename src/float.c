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
	return (getsize(n1_int) < getsize(result) ? 1 : 0);
}

char 			*ft_ftoa(double n, int afterpoint, char *specdot)
{
	t_binary64		d;
	unsigned short 	*part1;
	unsigned short	*part2;
	unsigned short 	*result;
	char 			*final;
	double			power;
	int				point;
	int				flag;

	d.d = n;
	point = 0;
	flag = d.s_parts.exp < 1023;
	if (flag)
	{
		power = ft_power(2, d.s_parts.exp - 1023);
		part1 = write_double(power, 0);
	}
	else
		part1 = pow_nb(2, d.s_parts.exp - 1023);
	part2 = write_double(d.s_parts.mantis / ft_power(2, 52), 1);
	point = flag ? 2 : part1[0] + 1 + check_overflow(part1, part2, flag);
	result = mult_nb(part1, part2);
	final = round_nb(result, point, afterpoint, d.s_parts.sign, specdot);
	free(part1);
	free(part2);
	free(result);
	return (final);
}

char 			*ft_lftoa(long double n, int afterpoint, char *specdot)
{
	t_binary80 		ld;
	int				point;
	int				flag;
	long double		power;
	unsigned short 	*part1;
	unsigned short 	*part2;
	unsigned short	*result;
	char			*final;

	ld.ld = n;
	point = 0;
	flag = ld.s_parts.exp < 16383;
	if (flag)
	{
		power = ft_power_l(2, ld.s_parts.exp - 16383);
		part1 = write_double(power, 0);
	}
	else
		part1 = pow_nb(2, ld.s_parts.exp - 16383);
	part2 = write_double(ld.s_parts.mantis / ft_power(2, 63), 0);
	point = flag ? 2 : part1[0] + 1 + check_overflow(part1, part2, flag);
	result = mult_nb(part1, part2);
	final = round_nb(result, point, afterpoint, ld.s_parts.sign, specdot);
	free(part1);
	free(part2);
	free(result);
	return (final);
}