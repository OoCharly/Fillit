/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:22:13 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 18:18:27 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i--;
	end = i;
	i = end - start + 1;
	return (ft_strncpy(ft_strnew(i), &s[start], i));
}
