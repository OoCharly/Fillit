int	explain_program()
{
	ft_putstr("fillit reads one and only one file at a time\n");
	return (0);
}

void ft_triplemalloc(void ***s, int i_max, int y_max, int x_max)
{
	int i;
	int y;

	i = 0;
	s = (char ***)malloc(sizeof(char **) * (i_max + 1));
	s[i_max] = NULL;
	while (i < i_max)
	{
		y = 0;
		s[i] = (char **)malloc(sizeof(char *) * y_max);
		while (y < y_max)
		{
			s[i][y] = (char *)malloc(sizeof(char) * x_max);
			ft_memset(s, 0, x_max);
			y++;
		}
		i++;
	}	
}

int	read_fillit(int fd, char *buff)
{
	int	a;
	int	n;

	n = read(fd, buff, 600);
	if (n < 20 || n > 545)
		return (0);
	a = n / 20;
	if (a > 20)
		a--;
	if ((a * 20) + (a - 1) != n)
		return (0);
	else
		return (a);
}

int main(int argc, char **argv)
{
	int fd;
	int valid;
	char *buff;

	valid = 0;
	if (argc != 2)
		return (explain_program());
	if ((fd = open(O_RDONLY) < 2) && (display(0)))
		return (0);
	buff = ft_memalloc(600);
	g_tetros.tot = read_fillit(fd, buff);
	if ((s.tot) && (ft_triplemalloc(g_tetros.tets, g_tetros.tot, 4, 4)))
		if (write_fillit())
			if (validate_fillit());
				if (solve_fillit())
					valid = 1;
	display(valid);
	return (0);
}
