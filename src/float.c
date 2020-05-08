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

int kek(unsigned short *a, unsigned short *b){
	double n1 = (b[b[0]] * 1.0) + (b[b[0] - 1] * 0.1) + (b[b[0] - 2] * 0.01) + (b[b[0] - 3] * 0.001);

	int n2 = 0;
	int i = 0;
	int jdkds = 0;
	while (i < 2)
		n2 = n2 * 10 + a[a[0] - i++];
	jdkds = n1 * n2;
	// printf("%f\n", n1);
	// printf("%d\n", n2);
	// exit(1);
	// printf("%d\n", jdkds);

	if (getsize(jdkds) > 2)
		return 1;
	return 0;
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
	}

	// printf("part1:\n%f\n", power_t(2, d.parts.exponent-1023));
	// printf("part2:\n%f\n", d.parts.mantissa / power_t(2, 52) + 1.0); // 1

	part2 = write_double(d.parts.mantissa / power_t(2, 52), 1);
	if (kek(part1, part2))
		point++;
	
	// printf("point:\n%d\n\n", point);

	result = mult_nb(part1, part2);
	// print432_nb(result);
	// exit(1);
	unsigned short *res22 = round_nb(result, point, afterpoint);
	// int point = b[0] + 1;

	str = nbtoa(res22, point, d.parts.sign);

	return str;
}
