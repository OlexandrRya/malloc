/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:00:12 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 11:00:20 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dswap;
	const char	*sswap;
	int			t;

	t = 0;
	dswap = dst;
	sswap = src;
	if (!n)
		return (NULL);
	if (dst != src)
		while (n--)
		{
			if (*sswap == (const char)c)
				t++;
			*dswap++ = *sswap++;
			if (t)
				return (dswap);
		}
	return (NULL);
}
