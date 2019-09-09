/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:55:05 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 15:55:07 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"

size_t	process_float(char **format, va_list *args, t_printf_arg *arg)
{
	float	nbr;

	(void)format;
	(void)arg;
	nbr = (float)va_arg(*args, double);
	(void)nbr;
	ft_putstr("Float");
	return (0);
}
