/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:34:40 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/16 17:58:25 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

void			*realloc(void *ptr, size_t size)
{
	void	*re_ptr;

	pthread_mutex_lock(&g_mutex);
	re_ptr = malloc(size);
	re_ptr = ft_strncpy(re_ptr, ptr, size);
	free(ptr);
	pthread_mutex_unlock(&g_mutex);
	return (re_ptr);
}
