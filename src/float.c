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

char *ft_ftoa(double n, int afterpoint) {
	double_cast d;
	d.d = n;
	unsigned short *part1;
	unsigned short *part2;
	unsigned short *result;
	char *str;
	double power;
	int point = 0;
	
	if (d.parts.exponent < 1023) {
		power = power_t(2, d.parts.exponent - 1023);
		part1 = write_double(power, 0);
		point = 1;
	}
	else {
		part1 = pow_nb(2, d.parts.exponent - 1023);
		point = part1[0];
	}	// 1
	// printf("%d\n", point);
	// exit(1);
	part2 = write_double(d.parts.mantissa / power_t(2, 52), 1); // 1 || 0

	result = mult_nb(part1, part2);
	// int point = b[0] + 1;

	str = nbtoa(result, point, d.parts.sign);

	return str;
}
