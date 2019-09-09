/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:32:28 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 12:32:31 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strstr(const char *str1, const char *str2)
{
	char	*a;
	char	*b;

	if (*str2 == '\0')
		return ((char *)str1);
	while (*str1)
	{
		a = (char *)str1;
		b = (char *)str2;
		while (*a && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
