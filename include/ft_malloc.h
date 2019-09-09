/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:19:22 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/16 20:39:22 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include <pthread.h>
# include "../libft/include/libft.h"
# define PAGE_SIZE			(size_t)getpagesize()
# define LINK_SIZE			(size_t)sizeof(t_link)
# define STRUCT_SIZE		(size_t)sizeof(t_struct)
# define TIN_PAGE_MAX 		8
# define TIN_SIZE 			(size_t)(TIN_PAGE_MAX * PAGE_SIZE)
# define SMALL_PAGE_MAX		32
# define SMALL_SIZE 		(size_t)(SMALL_PAGE_MAX * PAGE_SIZE)
# define TIN_COUNT_PAGE 	100
# define SMALL_COUNT_PAGE 	0
# define LARGE_COUNT_PAGE 	1
# define TIN_ZONE 			(size_t)(TIN_SIZE + LINK_SIZE) * TIN_COUNT_PAGE
# define SMALL_ZONE 		(size_t)(SMALL_SIZE + LINK_SIZE) * SMALL_COUNT_PAGE
# define TIN_TYPE 			1
# define SMALL_TYPE 		2
# define LARGE_TYPE 		3
# define LOC_MEMORY 		1
# define UNLOC_MEMORY 		0
# define WRITE_MEMORY 		(PROT_READ | PROT_WRITE)
# define MEMORY_MAP 		(MAP_ANON | MAP_PRIVATE)

typedef struct		s_link {
	void			*start;
	struct s_link	*next;
	uint8_t			free;
	size_t			count;
	size_t			size;
}					t_link;

typedef struct		s_struct {
	t_link			*tin;
	t_link			*small;
	t_link			*lrg;
}					t_struct;

void				*ft_malloc(size_t size);
void				free(void *ptr);
void				*ft_malloc(size_t size);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();
int					init_lrg_list(t_link **lrg);
void				*memory_data_init(size_t size);
t_link				*find_free_mem_list(t_link *list_mem, size_t count);
t_link				*return_memory_list(t_link *list_mem, size_t size_zone);
void				*alloc_mem(t_link *l, size_t s, size_t c);
int					get_type_zone(size_t zone_size);
t_link				*find_mem_list(void *ptr);
void				print_memory(const void *addr, size_t size);
t_struct			*g_mem;
pthread_mutex_t		g_mutex;

#endif
