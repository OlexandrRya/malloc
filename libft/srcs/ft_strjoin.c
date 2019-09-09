/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:49:31 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 11:49:34 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	while (s1[j])
	{
		str[i] = (unsigned char)s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = (unsigned char)s2[j];
		i++;
		j++;
	}
	return (str);
}
