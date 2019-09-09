/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:25:05 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/16 15:57:57 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

void	*ft_malloc(size_t size)
{
	void	*memory;

	memory_data_init(size);
	if (size <= 0 || size >= SIZE_MAX)
		return (NULL);
	if (get_type_zone(size) == TIN_TYPE)
	{
		memory = alloc_mem(g_mem->tin, TIN_ZONE, TIN_COUNT_PAGE);
	}
	if (get_type_zone(size) == SMALL_TYPE)
	{
		memory = alloc_mem(g_mem->small, SMALL_ZONE, SMALL_COUNT_PAGE);
	}
	if (get_type_zone(size) == LARGE_TYPE)
	{
		memory = alloc_mem(g_mem->lrg, size, LARGE_COUNT_PAGE);
	}
	if (memory == MAP_FAILED)
		return (NULL);
	return (memory);
}

void	*malloc(size_t size)
{
	void	*memory;

	if (!g_mem->tin && !g_mem->small && !g_mem->lrg)
	{
		pthread_mutex_init(&g_mutex, NULL);
	}
	pthread_mutex_lock(&g_mutex);
	memory = ft_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	return (memory);
}
