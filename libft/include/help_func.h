/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:40:40 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/27 12:40:47 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_FUNC_H
# define HELP_FUNC_H
# include <stdarg.h>
# include "ft_printf.h"
# include <stddef.h>
# include <stdint.h>
# include "find_all_elem.h"
# include "math_func.h"
# include "libft.h"

unsigned int	nbrlen(uintmax_t nbr, char *base);
unsigned int	calc_nbrstrlen(uintmax_t nbr, char *base,
		char *p, t_printf_arg *arg);
size_t			nbrforceprefix(uintmax_t i,
		char *base, t_printf_arg *arg, char *prefix);
void			ft_putnbrbase_fd(uintmax_t nbr, char *base, int fd);
void			ft_putnbrbase(uintmax_t nbr, char *base);
size_t			handle_uint(uintmax_t nbr,
		t_printf_arg *arg, char *base, char *prefix);
void			ft_putwchar(wchar_t chr);
void			ft_putwchar_fd(wchar_t chr, int fd);
void			ft_putwchar_fd(wchar_t chr, int fd);
void			ft_putnwstr(const wchar_t *str, size_t len);
#endif
