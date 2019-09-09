/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:38:58 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 14:39:01 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"
#include "../include/help_func.h"

static intmax_t	get_signed_from_length(va_list *args, t_printf_arg *arg)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->length == hh)
		nbr = (char)nbr;
	else if (arg->length == h)
		nbr = (short int)nbr;
	else if (arg->length == l)
		nbr = (long int)nbr;
	else if (arg->length == ll)
		nbr = (long long int)nbr;
	else if (arg->length == j)
		nbr = (intmax_t)nbr;
	else if (arg->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

size_t			process_int(char **format, va_list *args, t_printf_arg *arg)
{
	intmax_t				nbr;
	char					*prefix;

	(void)format;
	if (arg->have_precision)
		arg->null_flags = 0;
	nbr = get_signed_from_length(args, arg);
	if (nbr < 0 || arg->plus_flags || arg->space_flags)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (arg->plus_flags)
			prefix = "+";
		else if (arg->space_flags)
			prefix = " ";
		else
			prefix = "";
		return (nbrforceprefix(nbr, "0123456789", arg, prefix));
	}
	else
		return (handle_uint(nbr, arg, "0123456789", NULL));
}
