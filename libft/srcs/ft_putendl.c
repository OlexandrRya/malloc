/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:15:23 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 11:15:24 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	if (s == (void *)0)
		return ;
	while (*s)
		write(1, &(*s++), 1);
	ft_putchar('\n');
}
