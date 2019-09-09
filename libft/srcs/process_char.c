/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:33:18 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 15:33:20 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"

size_t	process_char(char **format, va_list *args, t_printf_arg *arg)
{
	(void)format;
	if (arg->length == l)
		return (process_wchar_t_char(format, args, arg));
	else
	{
		if (arg->have_width && !arg->minus_flags)
			width_layer(1, arg->width, arg->null_flags ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (arg->have_width && arg->minus_flags)
			width_layer(1, arg->width, ' ');
		return (arg->have_width ? ft_max(arg->width, 1) : 1);
	}
}
