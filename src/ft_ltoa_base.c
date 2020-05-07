/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:04:04 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/18 13:04:07 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define RADIXLO "0123456789abcdef"
#define RADIXHI "0123456789ABCDEF"

char	*ft_ltoa_base(unsigned long long int value, int base, int radix_case)
{
	int						i;
	unsigned long long		n;
	char					*s;
	char					*hex;

	i = 1;
	n = value;
	hex = radix_case ? RADIXHI : RADIXLO;
	while (n /= base)
		i++;
	if ((s = (char*)malloc(sizeof(char) * i + 1)) == 0 || (base < 2 &&
															base > 16))
		return (NULL);
	s[i] = 0;
	if (value == 0)
		s[0] = '0';
	n = value;
	while (n)
	{
		s[--i] = hex[n % base];
		n /= base;
	}
	return (s);
}
