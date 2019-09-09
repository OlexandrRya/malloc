/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:12:30 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 10:12:33 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"
#include "../include/math_func.h"
#include "../include/help_func.h"

static size_t	calc_wchar_t_strlen(wchar_t *str, int prec, size_t i)
{
	if (*str == '\0' || prec == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wchar_t_strlen(str + 1, prec - 1, i + 1));
	else if (*str <= 0x7FF && prec >= 2)
		return (calc_wchar_t_strlen(str + 1, prec - 2, i + 2));
	else if (*str <= 0xFFFF && prec >= 3)
		return (calc_wchar_t_strlen(str + 1, prec - 3, i + 3));
	else if (*str <= 0x10FFFF && prec >= 4)
		return (calc_wchar_t_strlen(str + 1, prec - 4, i + 4));
	else
		return (i);
}

static size_t	ft_wchar_t_strlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

size_t			process_wchar_t_str(char **format, va_list *args,
		t_printf_arg *arg)
{
	wchar_t	*str;
	size_t	len;

	(void)format;
	(void)arg;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	len = arg->have_precision ? calc_wchar_t_strlen(str, arg->precision, 0) :
			ft_wchar_t_strlen(str);
	if (arg->have_width && !arg->minus_flags)
		width_layer(len, arg->width, arg->null_flags ? '0' : ' ');
	ft_putnwstr(str, len);
	if (arg->have_width && arg->minus_flags)
		width_layer(len, arg->width, ' ');
	return (arg->have_width ? FT_MAX(len, arg->width) : len);
}
