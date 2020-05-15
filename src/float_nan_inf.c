/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_nan_inf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:18:56 by jirwin            #+#    #+#             */
/*   Updated: 2020/05/15 11:18:58 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_nan_inf64(t_binary64 d, double n)
{
	char	*result;
	int		sign;

	sign = -d.s_parts.sign;
	if (n != n)
	{
		result = (char *)malloc(sizeof(char) * 4 + sign);
		if (sign)
			ft_strcpy(result, "-nan");
		else
			ft_strcpy(result, "nan");
		return (result);
	}
	if (d.s_parts.exp == MAXEXP64)
	{
		result = (char *)malloc(sizeof(char) * 4 + sign);
		if (sign)
			ft_strcpy(result, "-inf");
		else
			ft_strcpy(result, "inf");
		return (result);
	}
	return (NULL);
}

char	*check_nan_inf80(t_binary80 d, long double n)
{
	char	*result;
	int		sign;

	sign = -d.s_parts.sign;
	if (n != n)
	{
		result = (char *)malloc(sizeof(char) * 4 + sign);
		if (sign)
			ft_strcpy(result, "-nan");
		else
			ft_strcpy(result, "nan");
		return (result);
	}
	if (d.s_parts.exp == MAXEXP80)
	{
		result = (char *)malloc(sizeof(char) * 4 + sign);
		if (sign)
			ft_strcpy(result, "-inf");
		else
			ft_strcpy(result, "inf");
		return (result);
	}
	return (NULL);
}
