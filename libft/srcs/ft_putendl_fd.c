/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:13:21 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 11:13:23 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	if (s == (void *)0)
		return ;
	while (*s)
		write(fd, &(*s++), 1);
	ft_putchar_fd('\n', fd);
}
