/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:13:15 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:20:30 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#define RADIXLO "0123456789abcdef"
#define RADIXHI "0123456789ABCDEF"

char	*ft_ltoa_base(unsigned long long int value, int base, int _radix_case)
{
	int	                    i;
	unsigned long long		n;
	char					*s;
	char					*hex;

	i = (value < 0 && base == 10) ? 2 : 1;
	n = value;
	hex = _radix_case ? RADIXHI : RADIXLO;
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