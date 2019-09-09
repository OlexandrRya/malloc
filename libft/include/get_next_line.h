/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:44:43 by oryabchu          #+#    #+#             */
/*   Updated: 2017/01/16 15:44:54 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# define BUFF_SIZE 1
# define F ((t_f_i_a_b *)(i->content))

typedef	struct	s_file_indef_and_buf
{
	int			indef;
	char		*buf;
}				t_f_i_a_b;
int				get_next_line(const int fd, char **line);
int				set_file_inform(t_f_i_a_b *elem, const int fd);
int				chek_fd_in_list(t_list *list, int fd, int *nil);
int				set_inform_in_line(t_list *list, char **line, int fd);
int				read_in_line(t_list *list, char **line, int *nil, char *str);
void			help_in_read(t_list *list, int nil, char *str);
#endif
