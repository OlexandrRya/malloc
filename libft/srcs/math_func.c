/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:37:23 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/17 14:39:05 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/math_func.h"

int			ft_max(int x, int y)
{
	return (x > y ? x : y);
}

size_t		ft_nstrlen(const char *str, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (*str++ && i < maxlen)
		i++;
	return (i);
}
