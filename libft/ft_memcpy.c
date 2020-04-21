/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:16:14 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/21 13:16:14 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst && src)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
	}
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}
