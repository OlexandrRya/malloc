/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 11:37:09 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 11:37:12 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/help_func.h"

void		ft_putnbrbase(uintmax_t nbr, char *base)
{
	ft_putnbrbase_fd(nbr, base, STDOUT_FILENO);
}

static void	ft_putnbrbp(uintmax_t nbr, char *base, t_printf_arg *arg,
		unsigned nbr_len)
{
	if (arg->have_precision)
		width_layer(nbr_len, arg->precision, base[0]);
	if (nbr == 0 && arg->have_precision && arg->precision == 0)
		return ;
	else
		ft_putnbrbase(nbr, base);
}

size_t		handle_uint_2_0(uintmax_t nbr,
		t_printf_arg *arg, char *base, char *prefix)
{
	unsigned int			nbrstrlen;
	unsigned int			nbr_len;

	nbr_len = nbrlen(nbr, base);
	nbrstrlen = calc_nbrstrlen(nbr, base, prefix, arg);
	if (arg->have_width && !arg->minus_flags)
		width_layer(nbrstrlen, arg->width, ' ');
	if (arg->grille_flags && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	if (prefix != NULL)
		if ((ft_strncmp(prefix, "0x", 2) || ft_strncmp(prefix, "0X", 2)) &&
			arg->precision > nbr_len && arg->precision < 10 &&
			arg->grille_flags && !arg->have_dot)
		{
			if ((arg->precision - nbr_len) != 1 && nbr_len < arg->precision)
				nbrstrlen -= 2;
			arg->precision = arg->precision - 2;
		}
	ft_putnbrbp(nbr, base, arg, nbr_len);
	if (arg->have_width && arg->minus_flags)
		width_layer(nbrstrlen, arg->width, ' ');
	return (arg->have_width ? FT_MAX(nbrstrlen, arg->width) : nbrstrlen);
}

size_t		handle_uint(uintmax_t nbr,
		t_printf_arg *arg, char *base, char *prefix)
{
	unsigned int			nbr_len;

	if (arg->have_precision)
		arg->null_flags = 0;
	nbr_len = nbrlen(nbr, base);
	if (arg->have_width && !arg->minus_flags && arg->null_flags)
	{
		if (arg->have_precision)
			arg->precision = ft_max(arg->width, arg->precision);
		else
			arg->precision = ft_max(arg->width, nbr_len);
		arg->have_precision = 1;
		arg->have_width = 0;
	}
	return (handle_uint_2_0(nbr, arg, base, prefix));
}
