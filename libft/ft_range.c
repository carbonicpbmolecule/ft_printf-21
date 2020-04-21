/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:16:40 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/21 13:16:40 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *ofints;

	i = 0;
	if (max <= min)
		return (NULL);
	if (!(ofints = (int *)malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (i < (max - min))
	{
		ofints[i] = i + min;
		i++;
	}
	return (ofints);
}
