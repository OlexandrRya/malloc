/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:34:41 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 12:34:44 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;
	size_t		j;

	j = 0;
	i = start;
	if (len == 1 && !s && start == 0)
	{
		str = ft_strnew(1);
		str[j] = '\0';
		return (str);
	}
	if (!s || !len)
		return (ft_strnew(len));
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (len-- && s[i])
	{
		str[j] = s[i];
		i++;
		j++;
	}
	return (str);
}
