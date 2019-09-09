/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:27:48 by oryabchu          #+#    #+#             */
/*   Updated: 2016/12/12 12:28:09 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int		nb_word(char const *s, char c)
{
	int		nb;
	int		i;
	int		word;

	i = 0;
	word = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c && word)
			word = !word;
		else if (s[i] != c && !word)
		{
			nb++;
			word = !word;
		}
		i++;
	}
	return (nb);
}

static	int		len_word(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		itab;
	char	**tab;
	int		lw;
	int		nbw;

	if (s == NULL)
		return (NULL);
	nbw = nb_word(s, c);
	itab = 0;
	tab = malloc(sizeof(char *) * (nbw + 1));
	if (tab == NULL)
		return (NULL);
	while (*s && itab < nbw)
	{
		while (*s && *s == c)
			s++;
		lw = len_word(s, c);
		tab[itab] = ft_strsub(s, 0, lw);
		itab++;
		while (*s && *s != c)
			s++;
	}
	tab[itab] = NULL;
	return (tab);
}
