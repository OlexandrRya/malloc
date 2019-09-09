/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:03:11 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/17 11:03:16 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "find_all_elem.h"

char	*parse_flags(char **format, t_printf_arg *arg);
char	*parse_width(char **format, va_list *list, t_printf_arg *arg);
char	*parse_precision(char **format, va_list *list, t_printf_arg *arg);
char	*parse_length(char **format, t_printf_arg *arg);
#endif
