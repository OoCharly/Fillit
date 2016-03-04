#include "fillit.h"

int	explain_program()
{
	ft_putstr("fillit reads one and only one file at a time\n");
	return (0);
}

int	ft_triplemalloc(char ***s, int i_max)
{
	int i;
	int y;

	i = 0;
	s = (char ***)malloc(sizeof(char **) * (i_max + 1));
	s[i_max] = NULL;
	while (i < i_max)
	{
		y = 0;
		s[i] = (char **)malloc(sizeof(char *) * 4);
		while (y < 4)
		{
			s[i][y] = (char *)malloc(sizeof(char) * 4);
			ft_memset(s, 0, 4);
			y++;
		}
		i++;
	}
	return (1);	
}

int		ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_pow(nb, power - 1));
}
