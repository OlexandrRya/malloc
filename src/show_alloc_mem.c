/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:59:22 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/16 20:57:03 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

static size_t	print_alloc_memory_ex(t_link *list, char *str, size_t tot)
{
	if (list && str)
	{
		ft_putstr(str);
		ft_printf("%p", list);
		ft_putchar('\n');
	}
	while (list)
	{
		if (list->free == 0)
		{
			ft_printf("%p-%p : %d", list->start, (void*)list->start
				+ list->size, list->size);
			ft_printf(" octets\n");
			ft_printf("Data: \n");
			print_memory(list->start, list->size);
			ft_putchar('\n');
			tot += list->size;
		}
		list = list->next;
	}
	return (tot);
}

static size_t	print_alloc_memory(t_link *list, char *str)
{
	size_t		tot;

	tot = 0;
	if (list && str)
	{
		ft_putstr(str);
		ft_printf("%p", list);
		ft_putchar('\n');
	}
	while (list)
	{
		if (list->free == 0)
		{
			ft_printf("%p-%p : %d  octets\n", list->start, (void*)list->start
				+ list->size, list->size);
			tot += list->size;
		}
		list = list->next;
	}
	return (tot);
}

void			show_alloc_mem(void)
{
	size_t		tot;

	pthread_mutex_lock(&g_mutex);
	tot = 0;
	tot += print_alloc_memory(g_mem->tin, "TINY: ");
	tot += print_alloc_memory(g_mem->small, "SMALL: ");
	tot += print_alloc_memory(g_mem->lrg, "LARGE: ");
	ft_putstr("total: ");
	ft_putnbr(tot);
	ft_putendl(" octets");
	pthread_mutex_unlock(&g_mutex);
}
