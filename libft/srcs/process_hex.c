/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:23:37 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 15:23:40 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"
#include "../include/help_func.h"

size_t	process_hex(char **format, va_list *args, t_printf_arg *arg)
{
	uintmax_t	nbr;

	nbr = get_unsigned_from_length(args, arg);
	if (**format == 'X')
		return (handle_uint(nbr, arg, "0123456789ABCDEF", "0X"));
	else
		return (handle_uint(nbr, arg, "0123456789abcdef", "0x"));
}
