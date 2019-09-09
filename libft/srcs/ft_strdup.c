/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:35:51 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 11:36:42 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char			*ft_strdup(const char *source)
{
	char	*new;

	new = malloc(ft_strlen(source) + 1);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, source);
	return (new);
}
