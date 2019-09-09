/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:56:54 by oryabchu          #+#    #+#             */
/*   Updated: 2017/03/17 10:57:01 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/find_all_elem.h"

char	*parse_length(char **format, t_printf_arg *arg)
{
	if (**format == 'h')
	{
		if (arg->length == none)
			arg->length = h;
		else if (arg->length == h)
			arg->length = hh;
		else if (arg->length == hh)
			arg->length = h;
		*format = *format + 1;
	}
	else if (**format == 'l' || **format == 'j' || **format == 'z')
	{
		arg->length = l;
		if (arg->length == ll)
			arg->length = l;
		else if (**format == 'j')
			arg->length = j;
		else if (**format == 'z')
			arg->length = z;
		(*format)++;
	}
	return (*format);
}

char	*parse_flags(char **format, t_printf_arg *arg)
{
	if (**format == '#' || **format == '0' || **format == '-' || **format == '+'
		|| **format == ' ')
	{
		if (**format == '#')
			arg->grille_flags = 1;
		else if (**format == '0')
			arg->null_flags = 1;
		else if (**format == '-')
			arg->minus_flags = 1;
		else if (**format == '+')
			arg->plus_flags = 1;
		else if (**format == ' ')
			arg->space_flags = 1;
		(*format)++;
		if (arg->minus_flags)
			arg->null_flags = 0;
		return (parse_flags(format, arg));
	}
	else
		return (*format);
}

char	*parse_width(char **format, va_list *list, t_printf_arg *arg)
{
	int	i;

	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			i = va_arg(*list, int);
			if (i < 0)
				arg->minus_flags = 1;
			arg->width = i < 0 ? -i : i;
			arg->have_width = 1;
		}
		if (ft_isdigit(**format))
		{
			arg->have_width = 1;
			arg->width = 0;
			while (ft_isdigit(**format))
				arg->width = arg->width * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

void	skip_a_sign(char **format, char ch)
{
	while (**format == ch)
		(*format)++;
}

char	*parse_precision(char **format, va_list *list, t_printf_arg *arg)
{
	int i;

	if (**format == '.')
	{
		arg->precision = 0;
		arg->have_dot = 1;
		skip_a_sign(format, '.');
		if (**format == '*')
		{
			skip_a_sign(format, '*');
			if ((i = va_arg(*list, int)) >= 0)
			{
				arg->have_precision = 1;
				arg->precision = i;
			}
		}
		else
		{
			while (ft_isdigit(**format))
				arg->precision = arg->precision * 10 + (*(*format)++ - '0');
			arg->have_precision = 1;
		}
	}
	return (*format);
}
