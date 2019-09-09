/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:53:56 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 11:54:00 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strncat(char *destptr, char *srcptr, size_t num)
{
	int		i;
	int		k;
	size_t	t;
	char	*tmp;

	i = ft_strlen(destptr);
	k = ft_strlen(srcptr);
	t = 0;
	tmp = destptr;
	while (k-- > 0 && t < num)
	{
		tmp[i] = srcptr[t];
		i++;
		t++;
	}
	tmp[i] = '\0';
	return (destptr);
}
