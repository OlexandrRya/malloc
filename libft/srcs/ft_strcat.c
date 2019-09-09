/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:19:48 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 11:19:51 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strcat(char *destination, const char *append)
{
	int		i;
	int		k;
	int		t;
	char	*tmp;

	i = ft_strlen(destination);
	k = ft_strlen(append);
	t = 0;
	tmp = destination;
	while (k-- > 0)
	{
		tmp[i] = append[t];
		i++;
		t++;
	}
	tmp[i] = '\0';
	return (destination);
}
