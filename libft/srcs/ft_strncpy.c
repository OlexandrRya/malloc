/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:19:44 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 12:19:48 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncpy(char *destptr, const char *srcptr, size_t num)
{
	char	*tmp;
	int		i;
	int		src_len;

	src_len = ft_strlen(srcptr);
	i = 0;
	tmp = destptr;
	while (num-- > 0)
	{
		if (srcptr[i] && i <= src_len)
			tmp[i] = srcptr[i];
		else
			tmp[i] = '\0';
		i++;
	}
	return (destptr);
}
