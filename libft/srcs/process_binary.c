/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:45:02 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 15:45:05 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/help_func.h"
#include "../include/libft.h"

size_t	process_binary(char **format, va_list *args, t_printf_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = get_unsigned_from_length(args, arg);
	return (handle_uint(nbr, arg, "01", "0b"));
}
