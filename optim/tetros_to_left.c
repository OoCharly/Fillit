/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rick_astley.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:14:30 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/04 14:35:21 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_empty_lines(int p)
{
	int	i;
	int	l;

	i = -1;
	l = 0;
	while (i++ < 15)
	{
		while (i % 5 != 4)
		{
			if (g_tetros.tets[p][i / 5][i % 5])
				return (l);
			i++;
		}
		l++;
	}
	return (l);
}

int		get_empty_columns(int p)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (i++ < 15)
	{
		while (i % 5 != 4)
		{
			if (g_tetros.tets[p][i % 5][i / 5])
				return (c);
			i++;
		}
		c++;
	}
	return (c);
}

void	move_left(int p, int c)
{
	int	i;
	int	j;

	j = 0;
	while (c != 4)
	{
		i = 0;
		while (i < 4)
		{
			g_tetros.tets[p][i][j] = g_tetros.tets[p][i][c + 1];
			i++;
		}
		j++;
		c++;
	}
	i = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
			g_tetros.tets[p][i++][j] = '\0';
		j++;
	}
}

void	move_up(int p, int l)
{
	int	i;
	int	j;

	j = 0;
	while (l != 4)
	{
		i = 0;
		while (i < 4)
		{
			g_tetros.tets[p][j][i] = g_tetros.tets[p][l + 1][i];
			i++;
		}
		j++;
		l++;
	}
	while (j < 4)
	{
		ft_memset(g_tetros.tets[p][j], 0, 4);
		j++;
	}
}

int	rearrange_tetros(void)
{
	int	l;
	int	p;

	p = 0;
	while (p < g_tetros.tot)
	{
		l = get_empty_columns(p);
		if (l)
			move_left(p, l);
		l = get_empty_columns(p);
		if (l)
			move_up(p, l);
		p++;
	}
	return (1);
}
