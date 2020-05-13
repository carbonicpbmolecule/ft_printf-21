/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_write_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 18:07:50 by jirwin            #+#    #+#             */
/*   Updated: 2020/05/13 18:07:52 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		long_write_double_ipart(unsigned short *result, \
											unsigned res_len, unsigned ipart)
{
	int		i;

	i = res_len - 1;
	result[0] = res_len - 1;
	i = res_len - 1;
	while (ipart)
	{
		result[i++] = ipart % 10;
		ipart /= 10;
	}
}

static void		long_write_double_fpart(unsigned short *result, \
											unsigned res_len, double fpart)
{
	int		i;
	int		tmp;

	i = res_len - 1 - 1;
	tmp = 0;
	while (i >= 1)
	{
		fpart *= 10;
		tmp = fpart;
		result[i--] = tmp;
		fpart -= tmp;
	}
}

unsigned short	*long_write_double(long double d, char flag)
{
	unsigned long	ipart;
	double			fpart;
	unsigned		res_len;
	unsigned short	*result;

	ipart = d;
	fpart = d - ipart;
	if (flag)
		ipart++;
	res_len = 1 + RIGOR + 1;
	result = (unsigned short *)malloc(sizeof(unsigned short) * res_len);
	if (!result)
		exit(1);
	long_nbzero(result, res_len);
	long_write_double_ipart(result, res_len, ipart);
	long_write_double_fpart(result, res_len, fpart);
	return (result);
}

unsigned short	*long_write_long_int(unsigned long n)
{
	int				i;
	int				len;
	unsigned short	*result;

	len = getsize(n) + 1;
	i = 1;
	result = (unsigned short *)malloc(sizeof(unsigned short) * len);
	if (!result)
		exit(1);
	long_nbzero(result, len);
	result[0] = len - 1;
	while (n)
	{
		result[i++] = n % 10;
		n /= 10;
	}
	return (result);
}
