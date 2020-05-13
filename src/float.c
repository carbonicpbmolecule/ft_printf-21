/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:20:49 by acyrenna          #+#    #+#             */
/*   Updated: 2020/05/13 16:35:08 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_overflow(unsigned short *part1, \
								unsigned short *part2, int flag)
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
	n2 = (part2[part2[0]] * 1.0) + (part2[part2[0] - 1] * 0.1) \
		+ (part2[part2[0] - 2] * 0.01) + (part2[part2[0] - 3] * 0.001);
	result = n1_int * n2;
	return (getsize(n1_int) < getsize(result) ? 1 : 0);
}

char			*adddottostr(char *str, char *specdot)
{
	int 			len;
	int				i;
	char			*result;

	if (ft_strchr(str, '.') == NULL && *specdot)
	{
		len = ft_strlen(str) + 1;
		result = (char *)malloc(sizeof(char) * len + 1);
		result[len] = 0;
		i = 0;
		while (str[i])
		{
			result[i] = str[i];
			i++;
		}
		result[i] = '.';
	}
	else
		result = str;
	*specdot = 0;
	return (result);
}

char 			*ftoa(double n, int afterpoint, char *specdot)
{
	t_binary64		d;
	t_sme			sme;
	char 			*final;
	double			d_part1;
	int				point;

	d.d = n;
	point = 0;
	sme.denorm = d.s_parts.exp < OFFSETBIN64;
	if (sme.denorm)
	{
		d_part1 = ft_power(2, d.s_parts.exp - OFFSETBIN64);
		sme.part1 = long_write_double(d_part1, 0);
	}
	else
		sme.part1 = long_pow(2, d.s_parts.exp - OFFSETBIN64);
	sme.part2 = long_write_double(d.s_parts.mantis / ft_power(2, 52), 1);
	point = sme.denorm ? 2 : sme.part1[0] + 1 \
			+ check_overflow(sme.part1, sme.part2, sme.denorm);
	sme.result = long_mult(sme.part1, sme.part2);
	final = long_round(sme.result, point, afterpoint, d.s_parts.sign);
	free(sme.part1);
	free(sme.part2);
	free(sme.result);
	return (adddottostr(final, specdot));
}

char 			*lftoa(long double n, int afterpoint, char *specdot)
{
	t_binary80 		ld;
	t_sme			sme;
	int				point;
	long double		d_part1;
	char			*final;

	ld.ld = n;
	point = 0;
	sme.denorm = ld.s_parts.exp < OFFSETBIN80;
	if (sme.denorm)
	{
		d_part1 = ft_power_l(2, ld.s_parts.exp - OFFSETBIN80);
		sme.part1 = long_write_double(d_part1, 0);
	}
	else
		sme.part1 = long_pow(2, ld.s_parts.exp - OFFSETBIN80);
	sme.part2 = long_write_double(ld.s_parts.mantis / ft_power(2, 63), 0);
	point = sme.denorm ? 2 : sme.part1[0] + 1 \
			+ check_overflow(sme.part1, sme.part2, sme.denorm);
	sme.result = long_mult(sme.part1, sme.part2);
	final = long_round(sme.result, point, afterpoint, ld.s_parts.sign);
	free(sme.part1);
	free(sme.part2);
	free(sme.result);
	*specdot = 0;
	return (final);
}