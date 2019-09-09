/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:32:30 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/27 11:32:33 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdarg.h>
#include "../include/find_all_elem.h"

size_t	process_null(char **format, va_list *args, t_printf_arg *arg)
{
	(void)args;
	if (arg->have_width && !arg->minus_flags)
		width_layer(1, arg->width, arg->null_flags ? '0' : ' ');
	ft_putchar(**format);
	if (arg->have_width && arg->minus_flags)
		width_layer(1, arg->width, ' ');
	return (arg->have_width ? ft_max(arg->width, 1) : 1);
}
