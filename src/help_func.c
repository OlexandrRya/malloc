/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:28:35 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/16 15:03:42 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

int	get_type_zone(size_t zone_size)
{
	if (zone_size <= TIN_SIZE)
	{
		return (TIN_TYPE);
	}
	if (zone_size <= SMALL_SIZE)
	{
		return (SMALL_TYPE);
	}
	return (LARGE_TYPE);
}
