/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:55:12 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 10:55:15 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"
#include "../include/help_func.h"

uintmax_t		get_unsigned_from_length(va_list *args, t_printf_arg *arg)
{
	uintmax_t	i;

	i = va_arg(*args, uintmax_t);
	if (arg->length == hh)
		i = (unsigned char)i;
	else if (arg->length == h)
		i = (unsigned short int)i;
	else if (arg->length == l)
		i = (unsigned long int)i;
	else if (arg->length == ll)
		i = (unsigned long long int)i;
	else if (arg->length == j)
		i = (uintmax_t)i;
	else if (arg->length == z)
		i = (size_t)i;
	else
		i = (unsigned int)i;
	return (i);
}

unsigned int	nbrlen(uintmax_t nbr, char *base)
{
	size_t			base_nbr;
	unsigned int	i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_nbr;
		i++;
	}
	return (i);
}

unsigned int	calc_nbrstrlen(uintmax_t nbr, char *base,
		char *p, t_printf_arg *arg)
{
	unsigned int	nbr_len;
	unsigned int	nbrstrlen;

	nbr_len = nbrlen(nbr, base);
	if (nbr == 0 && arg->have_precision && arg->precision == 0)
		nbrstrlen = 0;
	else if (arg->have_precision)
		nbrstrlen = ft_max(nbr_len, arg->precision);
	else
		nbrstrlen = nbr_len;
	if (arg->grille_flags && p != NULL && nbr != 0)
		nbrstrlen += ft_strlen(p);
	return (nbrstrlen);
}

size_t			nbrforceprefix(uintmax_t i,
		char *base, t_printf_arg *arg, char *prefix)
{
	unsigned	i_len;
	size_t		i_cut;

	i_len = calc_nbrstrlen(i, base, NULL, arg) +
		ft_strlen(prefix);
	i_cut = ft_strlen(prefix);
	if (arg->have_width && !arg->minus_flags && !arg->null_flags)
	{
		width_layer(i_len, arg->width, ' ');
		i_cut += ft_max(arg->width - i_len, 0);
		arg->have_width = 0;
	}
	else if (arg->have_width)
		arg->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	return (handle_uint(i, arg, base, NULL) + i_cut);
}
