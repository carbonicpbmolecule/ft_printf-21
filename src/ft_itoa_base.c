/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:11:11 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/18 13:11:16 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define RADIXLO "0123456789abcdef"
#define RADIXHI "0123456789ABCDEF"

char	*ft_itoa_base(long long int value, int base, int radix_case)
{
	int					i;
	long long int		n;
	char				*s;
	char				*hex;

	i = (value < 0 && base == 10) ? 2 : 1;
	n = value;
	hex = radix_case ? RADIXHI : RADIXLO;
	while (n /= base)
		i++;
	if ((s = (char*)malloc(sizeof(char) * i + 1)) == 0 || (base < 2 &&
															base > 16))
		return (NULL);
	s[i] = 0;
	if (value < 0 && base == 10)
		s[0] = '-';
	if (value == 0)
		s[0] = '0';
	n = value;
	while (n)
	{
		s[--i] = hex[(n < 0) ? -(n % base) : n % base];
		n /= base;
	}
	return (s);
}
