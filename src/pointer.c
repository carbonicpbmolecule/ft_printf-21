/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:14:35 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/29 20:14:37 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		handle_pointer(t_argument *arg, va_list *args)
{
	unsigned long long data;

	data = va_arg(*args, unsigned long long);
	if (!data)
	{
		arg->data = ft_strdup("(nil)");
		arg->special[0] = 0;
	}
	else
	{
		arg->data = ft_ltoa_base(data, 16, 0);
		if (!(*arg->special))
			ft_strcpy(arg->special, "0x");
	}
}
