/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:53:40 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/25 12:22:25 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src + i == dst)
		{
			ft_memcpy(dst + i, src + i, len - i);
			ft_memcpy(dst, src, i);
			return (dst);
		}
		i++;
	}
	return (ft_memcpy(dst, src, len));
}
