/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:15:18 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/17 13:15:22 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"
#include "../include/libft.h"
#define ALL_SYM "%sSpdDioOuUxXcC"

size_t	get_func_for_conversions_2(char **f, va_list *args, t_printf_arg *arg,
	int i)
{
	if (**f == 'U')
		i = process_long(f, args, arg);
	else if (**f == 'x')
		i = process_hex(f, args, arg);
	else if (**f == 'X')
		i = process_hex(f, args, arg);
	else if (**f == 'c')
		i = process_char(f, args, arg);
	else if (**f == 'C')
		i = process_wchar_t_char(f, args, arg);
	else if (**f == 'b')
		i = process_binary(f, args, arg);
	else if (**f == 'f')
		i = process_float(f, args, arg);
	else if (**f == 'n')
		i = process_charswritten(f, args, arg);
	else if (!chek_str(**f, ALL_SYM))
		i = process_null(f, args, arg);
	return (i);
}

size_t	get_func_for_conversions(char **f, va_list *args, t_printf_arg *arg)
{
	size_t	i;

	i = 0;
	if (**f == '%')
		i = process_escape(f, args, arg);
	else if (**f == 's')
		i = process_str(f, args, arg);
	else if (**f == 'S')
		i = process_wchar_t_str(f, args, arg);
	else if (**f == 'p')
		i = process_ptr(f, args, arg);
	else if (**f == 'd')
		i = process_int(f, args, arg);
	else if (**f == 'D')
		i = process_long(f, args, arg);
	else if (**f == 'i')
		i = process_int(f, args, arg);
	else if (**f == 'o')
		i = process_octal(f, args, arg);
	else if (**f == 'O')
		i = process_long(f, args, arg);
	else if (**f == 'u')
		i = process_unsigned(f, args, arg);
	return (get_func_for_conversions_2(f, args, arg, i));
}
