/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:20:37 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 15:20:40 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"
#include "../include/help_func.h"

size_t	process_unsigned(char **format, va_list *args, t_printf_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = get_unsigned_from_length(args, arg);
	return (handle_uint(nbr, arg, "0123456789", NULL));
}
