/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:51:56 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/04 19:20:51 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		xor_tetros(int x, int y, char **tet)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	while (i < 4 && n < 4 && (i + y) < g_grid.len)
	{
		j = 0;
		while (j < 4 && (j + x) < g_grid.len)
		{
			if (g_grid.tab[i + y][j + x] != '.' || tet[i][j])
			{
				if ((g_grid.tab[i + y][j + x] != '.')
						&& tet[i][j])
					return (0);
				else if (tet[i][j])
					n++;
			}
			j++;
		}
		i++;
	}
	return ((n == 4) ? 1 : 0);
}

void	place_piece(int current, int x, int y)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	while (n < 4 && (i + y) < g_grid.len)
	{
		j = 0;
		while (j < 4 && (j + x) < g_grid.len)
		{
			if (g_tetros.tets[current][i][j])
			{
				n++;
				g_grid.tab[i + y][j + x] = 'A' + current;
			}
			j++;
		}
		i++;
	}
}

void	erase_piece(int current, int x, int y)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	while (n < 4 && (i + y) < g_grid.len)
	{
		j = 0;
		while (j < 4 && (j + x) < g_grid.len)
		{
			if (g_grid.tab[i + y][j + x] == ('A' + current))
			{
				n++;
				g_grid.tab[i + y][j + x] = '.';
			}
			j++;
		}
		i++;
	}
}

int		find_place(int *x, int *y, int current)
{
	while (!xor_tetros(*x, *y, g_tetros.tets[current]))
	{
		(*x)++;
		if (*x == g_grid.len)
		{
			(*y)++;
			*x = 0;
			if (*y == g_grid.len)
				return (0);
		}
	}
	return (1);
}

int		place(int current)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (current == g_tetros.tot)
		return (1);
	while (x < (g_grid.len) && y < (g_grid.len))
	{
		if (!find_place(&x, &y, current))
		{
			return (0);
		}
		place_piece(current, x, y);
		if (place(current + 1))
			return (1);
		else
		{
			erase_piece(current, x, y);
			x = (++x == g_grid.len) ? 0 : x;
			y += (x == 0) ? 1 : 0;
		}
	}
	return (0);
}
