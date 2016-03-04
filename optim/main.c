#include "fillit.h"

/*if succesfuly parsed and solved, 
display grid. Else print "error"*/
 
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

int	alloc_init_grid()
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

int	solve()
{
	int	i;

	i = 2;
	while ((g_tetros.tot * 4) > ft_pow(i, 2))//get the theoritical minimal square
		i++;
	g_grid.len = i;
	if (!alloc_init_grid())
		return (0);
	i = 0;
	while (!place(0))
		g_grid.len++;
	return (1);
}

int	main(int argc, char **argv)
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
		if (get_tetros(buff,n))
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
/*
		if (rearrange_tetros())
			if (get_tetros(buff, read_fillit(fd, buff))
*/// You can't rearrange tetros before you get them
//// The rearrange function use the global struct which need to be filled with parsed tetros

/*Where does n in get_tetros come from? */
// comes from read_fillit and is the number of char read.
// Fixed the function read_fillit to change directly the g_tetros.tot
