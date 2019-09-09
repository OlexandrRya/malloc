/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:04:03 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/02 16:04:12 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/find_all_elem.h"
#include "../include/ft_printf.h"
#include "../include/parse.h"
#define ALL_SYM "%s SpdDioOuUxXcC#.0-+hljz123456789"

int		find_conversions(char c)
{
	char	*str;
	int		t;

	t = 0;
	str = "sSpdDioOuUxXcC";
	while (str[t] != '\0')
	{
		if (str[t] == c)
			return (1);
		t++;
	}
	return (0);
}

int		chek_str(char c, char *str)
{
	int		t;

	t = 0;
	while (str[t] != '\0')
	{
		if (str[t] == c)
			return (1);
		t++;
	}
	return (0);
}

size_t	separate_arg(char **f, va_list *args, t_printf_arg *arg)
{
	size_t					i;

	i = 0;
	while (chek_str(**f, ALL_SYM) && **f != '\0')
	{
		if (**f == '%')
			++*f;
		if (**f == '\0')
			return (i);
		if ((!parse_flags(f, arg)) || !parse_width(f, args, arg)
			|| !parse_precision(f, args, arg) || !parse_length(f, arg))
			return (-1);
		if (**f == '\0')
			return (i);
		if (chek_str(**f, "%sSpdDioOuUxXcC") || !chek_str(**f, ALL_SYM))
			break ;
	}
	i = get_func_for_conversions(f, args, arg);
	(*f)++;
	return (i);
}

size_t	separate_printf(const char *f, va_list *args, size_t str_len)
{
	int				len;
	t_printf_arg	arg;
	char			*str_n_e;

	str_n_e = ft_strchr(f, '%');
	if (*f == '\0')
		return (str_len);
	if (str_n_e == NULL)
	{
		ft_putstr(f);
		return (str_len + ft_strlen(f));
	}
	else if (str_n_e > f)
	{
		write(1, f, str_n_e - f);
		return (separate_printf(str_n_e, args, str_len + (str_n_e - f)));
	}
	else
	{
		ft_bzero(&arg, sizeof(arg));
		if ((len = separate_arg((char**)&f, args, &arg)) == -1)
			return (-1);
		else
			return (separate_printf(f, args, str_len + len));
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	if (format)
	{
		va_start(args, format);
		i = separate_printf(format, &args, 0);
		va_end(args);
	}
	return (i);
}
