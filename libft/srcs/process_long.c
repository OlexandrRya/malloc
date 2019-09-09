/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:45:22 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/18 14:45:30 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"

size_t	process_long(char **format, va_list *args, t_printf_arg *arg)
{
	size_t	i;

	arg->length = l;
	if (**format == 'D')
		i = process_int(format, args, arg);
	if (**format == 'O')
		i = process_octal(format, args, arg);
	if (**format == 'U')
		i = process_unsigned(format, args, arg);
	return (i);
}
