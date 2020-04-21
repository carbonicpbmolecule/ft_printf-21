/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:16:09 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/21 13:16:09 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxtlst;

	if (alst)
	{
		lst = *alst;
		while (lst)
		{
			nxtlst = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = nxtlst;
		}
		*alst = NULL;
	}
}
