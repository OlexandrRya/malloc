/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:36:35 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/16 15:56:30 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

static t_link	*search_ptr(t_link *list, void *ptr)
{
	t_link	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->start == ptr)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_link			*find_mem_list(void *ptr)
{
	t_link	*tmp;

	if ((tmp = search_ptr(g_mem->tin, ptr)) != NULL)
		return (tmp);
	if ((tmp = search_ptr(g_mem->small, ptr)) != NULL)
		return (tmp);
	if ((tmp = search_ptr(g_mem->lrg, ptr)) != NULL)
		return (tmp);
	return (NULL);
}
