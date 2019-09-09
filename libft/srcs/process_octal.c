/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:57:53 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 14:57:56 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"
#include "../include/help_func.h"

size_t	process_octal(char **format, va_list *args, t_printf_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = get_unsigned_from_length(args, arg);
	if (arg->grille_flags && nbr == 0 &&
				arg->have_precision && arg->precision == 0)
	{
		if (arg->have_width && !arg->minus_flags)
			width_layer(1, arg->width, arg->null_flags ? '0' : ' ');
		ft_putstr("0");
		if (arg->have_width && arg->minus_flags)
			width_layer(1, arg->width, ' ');
		return (arg->have_width ? ft_max(arg->width, 1) : 1);
	}
	else if (arg->grille_flags && nbr != 0)
	{
		arg->have_precision = 1;
		arg->precision = ft_max(arg->precision, nbrlen(nbr, "01234567") + 1);
	}
	return (handle_uint(nbr, arg, "01234567", NULL));
}
