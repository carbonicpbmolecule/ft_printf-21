/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:16:39 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/21 13:16:39 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new;

	if (n < 0)
	{
		new = -n;
		ft_putchar_fd('-', fd);
	}
	else
		new = n;
	if (new >= 10)
	{
		ft_putnbr_fd(new / 10, fd);
		ft_putchar_fd(new % 10 + '0', fd);
	}
	else
		ft_putchar_fd(new + '0', fd);
}
