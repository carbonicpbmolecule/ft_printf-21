/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:11:52 by jirwin            #+#    #+#             */
/*   Updated: 2020/05/15 11:13:57 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		free_parts(t_sme *sme)
{
	free(sme->part1);
	free(sme->part2);
	free(sme->result);
}

char			*ftoa(double n, int afterpoint, char *specdot)
{
	t_binary64		d;
	t_sme			sme;
	char			*final;
	double			d_part1;

	d.d = n;
	afterpoint = (afterpoint == -1) ? 0 : afterpoint;
	sme.afterpoint = (afterpoint < 0) ? -afterpoint : afterpoint;
	final = check_nan_inf64(d, n);
	if (final)
		return (final);
	sme.point = 0;
	sme.sign = d.s_parts.sign;
	sme.denorm = d.s_parts.exp < OFFSETBIN64;
	d_part1 = (sme.denorm) ? ft_power(2, d.s_parts.exp - OFFSETBIN64) : 0;
	if (sme.denorm)
		sme.part1 = long_write_double(d_part1, 0);
	else
		sme.part1 = long_pow(2, d.s_parts.exp - OFFSETBIN64);
	sme.part2 = long_write_double(d.s_parts.mantis / ft_power(2, 52), 1);
	sme.result = long_mult(sme.part1, sme.part2);
	sme.point = sme.denorm ? 2 : sme.result[0] - sme.part2[0] + 2;
	final = long_round(&sme, specdot);
	free_parts(&sme);
	return (final);
}

char			*lftoa(long double n, int afterpoint, char *specdot)
{
	t_binary80		ld;
	t_sme			sme;
	char			*final;
	long double		d_part1;

	ld.ld = n;
	afterpoint = (afterpoint == -1) ? 0 : afterpoint;
	sme.afterpoint = (afterpoint < 0) ? -afterpoint : afterpoint;
	final = check_nan_inf80(ld, n);
	if (final)
		return (final);
	sme.point = 0;
	sme.sign = ld.s_parts.sign;
	sme.denorm = ld.s_parts.exp < OFFSETBIN80;
	d_part1 = (sme.denorm) ? ft_power_l(2, ld.s_parts.exp - OFFSETBIN80) : 0;
	if (sme.denorm)
		sme.part1 = long_write_double(d_part1, 0);
	else
		sme.part1 = long_pow(2, ld.s_parts.exp - OFFSETBIN80);
	sme.part2 = long_write_double(ld.s_parts.mantis / ft_power(2, 63), 0);
	sme.result = long_mult(sme.part1, sme.part2);
	sme.point = sme.denorm ? 2 : sme.result[0] - sme.part2[0] + 2;
	final = long_round(&sme, specdot);
	free_parts(&sme);
	return (final);
}
