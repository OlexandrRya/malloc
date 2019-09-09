/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mem_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:23:51 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/16 15:34:36 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

int		init_lrg_list(t_link **lrg)
{
	*lrg = (t_link *)(g_mem + STRUCT_SIZE + 1);
	(*lrg)->start = (void *)(*lrg + LINK_SIZE + 1);
	(*lrg)->count = 0;
	(*lrg)->free = UNLOC_MEMORY;
	(*lrg)->next = NULL;
	(*lrg)->free = UNLOC_MEMORY;
	return (0);
}

void	*memory_data_init(size_t size)
{
	if (g_mem == NULL && !((g_mem = (t_struct *)mmap(NULL, STRUCT_SIZE + size,
		WRITE_MEMORY, MEMORY_MAP, -1, 0)) == MAP_FAILED))
		return (NULL);
	if (get_type_zone(size) == TIN_TYPE)
	{
		g_mem->tin = (t_link *)(g_mem + STRUCT_SIZE + 1);
		g_mem->tin->start = (void *)(g_mem->tin + LINK_SIZE + 1);
		g_mem->tin->count = 0;
		g_mem->tin->next = NULL;
		g_mem->tin->free = UNLOC_MEMORY;
	}
	if (get_type_zone(size) == SMALL_TYPE)
	{
		g_mem->small = (t_link *)(g_mem + STRUCT_SIZE + 1);
		g_mem->small->start = (void *)(g_mem->small + LINK_SIZE + 1);
		g_mem->small->count = 0;
		g_mem->small->next = NULL;
		g_mem->small->free = UNLOC_MEMORY;
	}
	if (get_type_zone(size) == LARGE_TYPE)
	{
		init_lrg_list(&(g_mem->lrg));
	}
	return (g_mem);
}

t_link	*find_free_mem_list(t_link *list_mem, size_t count_page)
{
	t_link	*ptr;
	t_link	*last;

	ptr = list_mem;
	while (ptr)
	{
		if (ptr->free == UNLOC_MEMORY)
			return (ptr);
		ptr = ptr->next;
		last = ptr;
	}
	if (last->count % count_page != 0)
	{
		ptr = (t_link *)(last + TIN_ZONE + 1);
		ptr->next = NULL;
		ptr->count = last->count + 1;
		ptr->free = UNLOC_MEMORY;
		ptr->start = (void *)(ptr + LINK_SIZE + 1);
		last->next = ptr;
		return (ptr);
	}
	return (NULL);
}

t_link	*return_memory_list(t_link *list_mem, size_t size_zone)
{
	t_link	*last;
	t_link	*ptr;

	last = list_mem;
	while (last->next)
		last = last->next;
	if ((ptr = (t_link *)mmap(NULL, size_zone,
			WRITE_MEMORY, MEMORY_MAP, -1, 0)) == MAP_FAILED)
		return (NULL);
	last->next = ptr;
	ptr->next = NULL;
	ptr->count = last->count + 1;
	ptr->free = UNLOC_MEMORY;
	ptr->start = (void *)(ptr + LINK_SIZE + 1);
	return (ptr);
}

void	*alloc_mem(t_link *link, size_t zone_size, size_t count)
{
	t_link	*mem;

	if ((mem = find_free_mem_list(link, count)) == NULL)
	{
		mem = return_memory_list(g_mem->tin, zone_size);
	}
	mem->size = zone_size;
	mem->free = LOC_MEMORY;
	if (mem != NULL)
		return (mem->start);
	return (NULL);
}
