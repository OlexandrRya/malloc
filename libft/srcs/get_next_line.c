/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:43:57 by oryabchu          #+#    #+#             */
/*   Updated: 2017/01/16 15:43:58 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int		set_file_inform(t_f_i_a_b *elem, const int fd)
{
	elem->indef = fd;
	elem->buf = NULL;
	return (0);
}

int		chek_fd_in_list(t_list *list, int fd, int *nil)
{
	t_list	*i;
	int		number_in_list;

	i = list;
	(nil[0]) = 0;
	number_in_list = 0;
	if (i == NULL)
	{
		return (1);
	}
	while (i)
	{
		if (F->indef == fd)
		{
			nil[2] = number_in_list;
			nil[0] = number_in_list;
			return (0);
		}
		i = i->next;
		number_in_list++;
	}
	return (1);
}

void	help_in_read(t_list *list, int nil, char *str)
{
	t_list		*i;
	t_f_i_a_b	*elem;
	char		*tmp;
	int			t;
	int			l;

	i = list;
	l = -1;
	while (++l < nil)
		i = i->next;
	elem = F;
	while ((t = read(elem->indef, str, BUFF_SIZE)) || elem->buf == 0)
	{
		if (elem->buf != NULL)
		{
			tmp = elem->buf;
			elem->buf = ft_strjoin(elem->buf, str);
			ft_memdel((void **)&tmp);
		}
		else
			elem->buf = ft_strcpy(ft_strnew(ft_strlen(str) + 1), str);
		if (ft_memchr(str, '\n', BUFF_SIZE))
			break ;
		ft_bzero(str, ft_strlen(str));
	}
}

int		read_in_line(t_list *list, char **line, int *nil, char *str)
{
	t_list		*i;
	char		*tmp;
	t_f_i_a_b	*elem;

	i = list;
	while ((nil[2])--)
		i = i->next;
	elem = F;
	help_in_read(list, nil[0], str);
	tmp = elem->buf;
	while (tmp[nil[1]] && tmp[nil[1]] != '\n')
		(nil[1])++;
	if (ft_strlen(tmp) != 0)
	{
		*line = ft_strncat(ft_strnew(nil[1]), tmp, (nil[1]));
		if (tmp[nil[1]] != '\0')
			(nil[1])++;
		elem->buf = ft_strcpy(ft_strnew(ft_strlen(elem->buf + nil[1])),\
		(elem->buf + nil[1]));
		ft_memdel((void **)&tmp);
		return (1);
	}
	else
		*line = ft_strnew(0);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	char			*str;
	t_f_i_a_b		elem;
	int				nil[3];

	if (BUFF_SIZE <= 0)
		return (-1);
	str = ft_strnew(BUFF_SIZE);
	if (fd < 0 || (read(fd, str, 0) == -1) || fd == 1)
		return (-1);
	nil[0] = 0;
	nil[1] = 0;
	nil[2] = 0;
	if ((chek_fd_in_list(list, fd, nil)))
	{
		if (!set_file_inform(&elem, fd))
			ft_lstadd(&list, ft_lstnew(&elem, sizeof(elem)));
		else
			return (-1);
	}
	nil[0] = read_in_line(list, line, nil, str);
	free(str);
	return (*nil);
}
