/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:27:31 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/04 18:30:08 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display(int opt)
{
	int i;

	i = 0;
	if (opt == 0)
	{
		ft_putstr("error\n");
		return ;
	}
	while (i < g_grid.len)
	{
		write(1, g_grid.tab[i], g_grid.len);
		write(1, "\n", 1);
		i++;
	}
}

int		alloc_init_grid(void)
{
	int	i;

	i = 0;
	if (!(g_grid.tab = (char**)malloc(sizeof(char*) * 105)))
		return (0);
	while (i < 105)
	{
		if (!(g_grid.tab[i] = (char*)malloc(sizeof(char) * 105)))
			return (0);
		i++;
	}
	i = 0;
	while (i < 11025)
	{
		g_grid.tab[i / 106][i % 106] = '.';
		i++;
	}
	return (1);
}

int		solve(void)
{
	int	i;

	i = 2;
	while ((g_tetros.tot * 4) > ft_pow(i, 2))
		i++;
	g_grid.len = i;
	if (!alloc_init_grid())
		return (0);
	i = 0;
	while (!place(0))
	{
		g_grid.len++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		valid;
	char	buff[601];
	int		n;

	valid = 0;
	if (argc != 2)
		return (explain_program());
	fd = open(argv[1], O_RDONLY);
	n = read_fillit(fd, buff);
	g_tetros.tets = ft_triplemalloc(g_tetros.tot);
	if (g_tetros.tets && fd > 2 && n)
	{
		if (get_tetros(buff, n))
		{
			if (rearrange_tetros())
			{
				solve();
				valid = 1;
			}
		}
	}
	display(valid);
	return (0);
}
