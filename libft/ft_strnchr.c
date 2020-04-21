/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:18:33 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/21 13:18:36 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s1, int c, int len)
{
	if (!len || !s1)
		return (0);
	while (*s1 != (char)c && len--)
		if (!*s1++)
			return (NULL);
	if (*s1 != (char)c)
		return (0);
	return ((char *)s1);
}
