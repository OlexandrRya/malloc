/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_escape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:53:19 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/17 14:53:22 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/math_func.h"

void	width_layer(int len, int width, char c)
{
	while (len < width)
	{
		ft_putchar(c);
		len++;
	}
}

size_t	process_escape(char **format, va_list *args, t_printf_arg *arg)
{
	(void)format;
	(void)args;
	(void)arg;
	if (arg->have_width && !arg->minus_flags)
		width_layer(1, arg->width, arg->null_flags ? '0' : ' ');
	ft_putchar('%');
	if (arg->have_width && arg->minus_flags)
		width_layer(1, arg->width, ' ');
	return (arg->have_width ? ft_max(arg->width, 1) : 1);
}

size_t	process_str(char **format, va_list *args, t_printf_arg *arg)
{
	char	*str;
	size_t	strlen;

	if (arg->length == l)
		return (process_wchar_t_str(format, args, arg));
	else
	{
		str = va_arg(*args, char*);
		if (str == NULL)
			str = "(null)";
		strlen = arg->have_precision ? ft_nstrlen(str, arg->precision) :
				ft_strlen(str);
		if (arg->have_width && !arg->minus_flags)
			width_layer(strlen, arg->width, arg->null_flags ?
					'0' : ' ');
		write(1, str, strlen);
		if (arg->have_width && arg->minus_flags)
			width_layer(strlen, arg->width, ' ');
		return (arg->have_width ? FT_MAX(strlen, arg->width) : strlen);
	}
}

size_t	process_ptr(char **format, va_list *args, t_printf_arg *arg)
{
	char		*all;
	uintmax_t	i;

	(void)format;
	arg->length = z;
	if (arg->have_precision)
		arg->null_flags = 0;
	all = "0123456789abcdef";
	i = get_unsigned_from_length(args, arg);
	return (nbrforceprefix(i, all, arg, "0x"));
}
