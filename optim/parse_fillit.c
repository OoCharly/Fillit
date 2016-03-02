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
		return (am_i_valid(buff, n));
}

int	am_i_valid(char *buff, int n)
{
	int	i;
	int	l;
	int	c;

	i = 0;
	l = 0;
	t = 0;
	while (i != n)
	{
		while(l != 4)
		{
			g_tetros.tets[p][
