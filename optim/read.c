#include "fillit.h"

int		get_tetros(char *buff, int n)
{
	int	i;
	int	p;
	int a;

	i = -1;
	p = 0;
	while (i++ < n)
	{
		a = check_tetros(&buff[i], p);
		if (a < 21)
			return (0);
		i += a;
		if (buff[i] != '\n' && buff[i] != '\0')
			return (0);
		p++;
	}
	return (1);
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
