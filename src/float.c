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
#include <math.h>

static double power_t(double x, long n) {
    if(n == 0) return 1.0;
    if(n < 0) return 1.0 / (x * power_t (1.0 / x, n + 1));
    return x * power_t(x, n - 1);
}

int kek(unsigned short *a, unsigned short *b, int flag)
{
	double n1;
	int n1_int = 0;
	if (flag)
		n1 = (a[a[0]] * 1.0) + (a[a[0] - 1] * 0.1) + (a[a[0] - 2] * 0.01) + (a[a[0] - 3] * 0.001);
	else
	{
		int i = a[0];
		while (i > 0)
			n1_int = n1_int * 10 + a[i--];
		n1 = n1_int;
	}

	double n2 = (b[b[0]] * 1.0) + (b[b[0] - 1] * 0.1) + (b[b[0] - 2] * 0.01) + (b[b[0] - 3] * 0.001);
	int point = 0;

	int ipart = n1 * n2;

	if (ipart == 0)
		return 1;
	while (ipart)
	{
		ipart /= 10;
		point++;
	}
	return point;
}

char *ft_ftoa(double n, int afterpoint) {
	double_cast d;
	d.d = n;
	unsigned short 	*part1;
	unsigned short	*part2;
	unsigned short 	*result;
	char 			*final;
	char *str;
	double power;
	int point = 0;
	int flag = d.parts.exponent < 1023;
	if (flag) {
		power = power_t(2, d.parts.exponent - 1023);
		part1 = write_double(power, 0);
	}
	else {
		part1 = pow_nb(2, d.parts.exponent - 1023);
		// show_mem_a(part1, 0);
	}

	part2 = write_double(d.parts.mantissa / power_t(2, 52), 1);

	// show_mem_a(part1, 1);
	// show_mem_a(part2, 0);


	result = mult_nb(part1, part2);

	// show_mem_a(result, 0);
	point = kek(part1, part2, flag);
	final = round_nb(result, point, afterpoint, d.parts.sign);
	return final;
}
