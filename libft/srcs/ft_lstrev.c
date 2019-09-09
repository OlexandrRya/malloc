/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:44:21 by oryabchu          #+#    #+#             */
/*   Updated: 2017/01/05 12:44:22 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	if (alst)
	{
		cur = *alst;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		*alst = prev;
	}
}
