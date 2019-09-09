/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:22:25 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 12:22:28 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		while (s1 || s2 || n--)
		{
			if (s1[i] == s2[i])
				i++;
			if (s1[i] == '\0' && s2[i] == '\0')
				return (1);
			if (i == n)
				return (1);
			if (s1[i] != s2[i])
				return (0);
		}
	}
	return (0);
}
