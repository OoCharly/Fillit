/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:02:24 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 18:15:45 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		while (*s1 == *s2 && *s1 && *s2)
		{
			s1++;
			s2++;
		}
		if (*s1 == *s2)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
