/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:25:25 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 11:29:54 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strcpy(char *destptr, const char *srcptr)
{
	int i;

	i = 0;
	while (srcptr[i] != '\0')
	{
		destptr[i] = srcptr[i];
		i++;
	}
	destptr[i] = '\0';
	return (destptr);
}
