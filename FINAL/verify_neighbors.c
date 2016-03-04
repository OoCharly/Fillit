/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_neighbors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:51:30 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/04 18:53:03 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_neighbours(int p, int l, int i)
{
	int	out;

	out = 0;
	if (l != 0)
	{
		if (g_tetros.tets[p][l - 1][i])
			out++;
	}
	if (i != 0)
	{
		if (g_tetros.tets[p][l][i - 1])
			out++;
	}
	if (i != 3)
	{
		if (g_tetros.tets[p][l][i + 1])
			out++;
	}
	if (l != 3)
	{
		if (g_tetros.tets[p][l + 1][i])
			out++;
	}
	return (out);
}

int		get_cohesion(int p)
{
	int	i;
	int	pass;
	int	tmp;

	i = -1;
	pass = 0;
	while (++i < 20)
	{
		while ((i % 5) != 4)
		{
			if (g_tetros.tets[p][i / 5][i % 5])
			{
				tmp = get_neighbours(p, i / 5, i % 5);
				if (tmp == 0)
					return (0);
				if (tmp > 1)
					pass = 1;
			}
			i++;
		}
	}
	return (pass);
}
