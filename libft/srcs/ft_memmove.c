/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:08:10 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 11:08:19 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst2;
	unsigned char *src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst2 < src2)
	{
		while (len--)
		{
			*(unsigned char *)dst2 = *(unsigned char *)src2;
			dst2++;
			src2++;
		}
	}
	else if (dst == src2)
		return (dst);
	else
	{
		while (len--)
		{
			*((unsigned char *)dst2 + len) = *((unsigned char *)src2 + len);
		}
	}
	return (dst);
}
