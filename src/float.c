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

#include "../inc/ft_printf.h"
#include <math.h>

char *ft_ftoa(double n, int afterpoint) {
	double_cast d;
	d.d = n;

	unsigned short *a = write_double(d.parts.mantissa / pow(2, 52), 1); // 1 || 0
	unsigned short *b = pow_nb(2, d.parts.exponent - 1023); // b[0]
	unsigned short *r = mult_nb(a, b);
	// int point = b[0] + 1;

	char *result = nbtoa(r, 0);

	free(a);
	free(b);
	free(r);
	
	return result;
}
