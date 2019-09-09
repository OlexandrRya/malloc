/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_wchar_t_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:36:18 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 15:36:21 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"
#include <wchar.h>
#include "../include/help_func.h"

size_t	process_wchar_t_char(char **format, va_list *args, t_printf_arg *arg)
{
	wchar_t		chr;
	unsigned	chr_len;

	(void)format;
	chr = (wchar_t)va_arg(*args, wint_t);
	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	if (arg->have_width && !arg->minus_flags)
		width_layer(chr_len, arg->width, arg->null_flags ? '0' : ' ');
	ft_putwchar(chr);
	if (arg->have_width && arg->minus_flags)
		width_layer(chr_len, arg->width, arg->null_flags ? '0' : ' ');
	return (arg->have_width ? FT_MAX(chr_len, arg->width) : chr_len);
}
