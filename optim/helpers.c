#include "fillit.h"

int	explain_program()
{
	ft_putstr("fillit reads one and only one file at a time\n");
	return (0);
}

int ft_triplemalloc(char ***s, int i_max, int y_max, int x_max)
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
	return (1);	
}
