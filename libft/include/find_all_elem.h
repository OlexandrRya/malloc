/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_elem.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:50:42 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/06 13:50:49 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_ALL_ELEM_H
# define FIND_ALL_ELEM_H
# include <stdarg.h>
# include "ft_printf.h"
# include <stddef.h>
# include <stdint.h>
# include "libft.h"
# include "math_func.h"
# include <stdio.h>

typedef struct					s_printf_arg
{
	int				grille_flags : 1;
	int				null_flags : 1;
	int				minus_flags : 1;
	int				plus_flags : 1;
	int				space_flags : 1;
	int				have_width : 1;
	int				have_precision : 1;
	int				have_dot : 1;
	unsigned int	width;
	unsigned int	precision;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
}								t_printf_arg;
int								chek_str(char c, char *str);
size_t							get_func_for_conversions(char **f,
		va_list *args, t_printf_arg *arg);
size_t							get_func_for_conversions_2(char **f,
		va_list *args, t_printf_arg *arg, int i);
size_t							separate_printf(const char *format,
		va_list *args, size_t str_len);
size_t							separate_arg(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_escape(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_str(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_ptr(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_wchar_t_str(char **format,
		va_list *args, t_printf_arg *arg);
size_t							process_int(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_long(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_octal(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_unsigned(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_hex(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_char(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_wchar_t_char(char **format,
		va_list *args, t_printf_arg *arg);
size_t							process_binary(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_float(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_null(char **format, va_list *args,
		t_printf_arg *arg);
size_t							process_charswritten(char **format,
		va_list *args, t_printf_arg *arg);
size_t							nbrforceprefix(uintmax_t i,
		char *base, t_printf_arg *arg, char *prefix);
uintmax_t						get_unsigned_from_length(va_list *args,
		t_printf_arg *arg);
void							width_layer(int len, int width, char c);
size_t							nbrforceprefix(uintmax_t i,
		char *base, t_printf_arg *arg, char *prefix);
#endif
