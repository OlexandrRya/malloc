/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:56:46 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/16 16:13:49 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

static void		unmap_large_zone(t_link *ptr)
{
	t_link	*tmp;

	tmp = g_mem->lrg;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		if (tmp->next == ptr)
		{
			tmp->next = tmp->next->next;
			munmap(ptr, ptr->size);
			return ;
		}
		tmp = tmp->next;
	}
}

static void		ft_free(void *ptr)
{
	t_link	*tmp;

	if (!ptr)
		return ;
	tmp = find_mem_list(ptr);
	if (tmp && tmp->size > SMALL_ZONE)
		unmap_large_zone(tmp);
	if (tmp)
		tmp->free = 1;
}

void			free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	ft_free(ptr);
	pthread_mutex_unlock(&g_mutex);
}
