/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:43:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 22:36:24 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nwords(char const *s, char c)
{
	int		w;

	w = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (w);
		w++;
		while (*s != c && *s)
			s++;
	}
	return (w);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**out;
	int		size;
	int		i;

	if (!(out = (char**)malloc(sizeof(char*) * (ft_nwords(s, c) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (s[size] != c && s[size])
			size++;
		out[i] = ft_strncpy(ft_strnew(size), s, size);
		s += size;
		if (!out[i])
			return (NULL);
		i++;
	}
	out[i] = NULL;
	return (out);
}
