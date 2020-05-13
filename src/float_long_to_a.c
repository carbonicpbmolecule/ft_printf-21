/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_long_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:57:34 by jirwin            #+#    #+#             */
/*   Updated: 2020/05/13 18:00:53 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*long_ltoa(unsigned short *c, int point, int afterpoint, int sign)
{
	char 				*result;
	int 				str_len;
	int 				i;
	int 				c_len;
	str_len = point - 1 + afterpoint;
	str_len += (afterpoint) ? 1 : 0;
	str_len += (sign < 0) ? 1 : 0;

	result = (char *)malloc(sizeof(char) * str_len + 1);
	if (!result)
		exit(1);
	i = 0;
	c_len = c[0];
	if (sign < 0)
		result[i++] = '-';
	while (i < str_len)
	{
		if (!afterpoint && i == point - 1 + (sign < 0))
			result[i++] = '.';

		if (!afterpoint && i == point - 1 + (sign < 0))
			break ;
		if (i == point - 1 + (sign < 0))
		{
			result[i++] = '.';
		}
		result[i] = c[c_len] + '0';
		i++;
		c_len--;
	}
	result[str_len] = 0;
	return (result);
}

char	*long_round(unsigned short *n, int point, \
											int afterpoint, char sign)
{
	unsigned short 		number1[n[0] + 1];
	unsigned short 		number2[n[0] + 1];
	unsigned short 		*result;
	int 				power;
	int 				i;

	long_nbcopy(number1, n);
	if (afterpoint == -1)
		afterpoint = 0;
	power = n[0] - (point - 1) - afterpoint;

	i = 1;
	number2[0] = power;
	while (i < number2[0])
		number2[i++] = 0;
	number2[i] = 5;
	result = long_add(number1, number2, &point);
	return (long_ltoa(result, point, afterpoint, sign));
}