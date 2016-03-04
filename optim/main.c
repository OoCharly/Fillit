#include "fillit.h"

/*if succesfuly parsed and solved, 
display grid. Else print "error"*/
 
int display(int opt)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (opt == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	while (y < g_grid.len)
	{
		x = 0;
		while (x < g_grid.len)
		{
			ft_putchar(g_grid.tab[y][x]);
			x++;
		}
		y++;
	}
	return (1);
}
int main(int argc, char **argv)
{
	int fd;
	int valid;
	char *buff;

	valid = 0;
	if (argc != 2)
		return (explain_program());
	if ((fd = open(argv[1], O_RDONLY) < 2) && (display(0)))
		return (0);
	buff = ft_memalloc(600);
	g_tetros.tot = read_fillit(fd, buff);
	if ((g_tetros.tot) && (ft_triplemalloc(g_tetros.tets, g_tetros.tot, 4, 4)))
		if (rearrange_tetros())
			/*Where does n in get_tetros come from? */
			if (get_tetros(buff, 0))
				if (solve())
					valid = 1;
	display(valid);
	return (0);
}
