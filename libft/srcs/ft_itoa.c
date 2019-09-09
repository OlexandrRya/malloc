/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 10:57:18 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 10:57:21 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_itoa_set(char **str, unsigned int n, int sign)
{
	int		i;
	int		t;

	i = 0;
	t = n;
	while (t != 0)
	{
		i++;
		t = t / 10;
	}
	if (sign)
		i++;
	*str = ft_strnew(i);
	if (!*str)
	{
		return ;
	}
	(*str)[t] = '\0';
	while (--i != -1)
	{
		(*str)[i] = 48 + (n % 10);
		n = n / 10;
	}
	if (sign)
		*str[0] = '-';
}

char		*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strnew(n + 1);
		str[0] = '0';
		return (str);
	}
	if (n >= 0)
	{
		ft_itoa_set(&str, n, 0);
	}
	else
	{
		ft_itoa_set(&str, n * (-1), 1);
	}
	return (str);
}
