/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yolos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:13:04 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/02 14:12:22 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		xor_tetro(int x, int y, char **tet)
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
			if (g_grid.tab[i + y][j + x] || tet[i][j])
			{
				if (g_grid.tab[i + y][j + x] && tet[i][j])
					return (0);
				else
					n++;
			}
			j++;
		}
		i++;
	}
	return ((n == 4) ? 1 : 0);
}

int		place(int current)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (current == g_tetros.tot)
		return (1);
	while (x < g_grid.len - 1 && y < g_grid.len - 1)
	{
		if (!find_place(&x, &y, current))
			return (0);
		place_piece(current, x, y);
		if (place(current + 1))
			return (1);
		else
		{
			erase_piece(current, x, y);
			x++;
		}
	}
	return (0);
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
			if (g_grid.tab[i][j] == ('A' + current))
			{
				n++;
				g_grid.tab[i + y][j + x] = '\0';
			}
			j++;
		}
		i++;
	}
}

void	find_place(int *x, int *y, int current)
{
	while (!xor_tetro(*x, *y, g_tetros.tets[current]))
	{
		(*x)++;
		if (*x == len)
		{
			(*y)++;
			*x = 0;
			if (*y == len)
				return (0);
		}
	}
	return (1);
}
