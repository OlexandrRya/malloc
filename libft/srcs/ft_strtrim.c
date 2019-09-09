/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:36:12 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 12:36:14 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(const char *s2)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	if (!s2)
		return ("\0");
	if (*s2 == '\0')
		return (ft_strnew(0));
	while ((s2[j] == ' ' || s2[j] == '\t' || s2[j] == '\n'))
		j++;
	i = ft_strlen(s2);
	while ((s2[i - 1] == ' ' || s2[i - 1] == '\t' || s2[i - 1] == '\n')\
	&& s2[j])
		i--;
	if (!(i - j))
		return (ft_strnew(0));
	str = ft_strsub(s2, j, i - j);
	if (!str)
		return (NULL);
	return (str);
}
