/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:39:33 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/17 14:39:37 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_FUNC_H
# define MATH_FUNC_H
# define FT_MIN(x, y) (x) < (y) ? (x) : (y)
# define FT_MAX(x, y) (x) > (y) ? (x) : (y)
# include <string.h>

int		ft_max(int x, int y);
size_t	ft_nstrlen(const char *str, size_t maxlen);
#endif
