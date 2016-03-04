#include "fillit.h"

int	explain_program()
{
	ft_putstr("fillit reads one and only one file at a time\n");
	return (0);
}

char	***ft_triplemalloc(int i_max)
{
	int		i;
	int		y;
	char	***s;

	i = 0;
	if (!(s = (char ***)malloc(sizeof(char **) * (i_max + 1))))
		return (NULL);
	while (i < i_max)
	{
		y = 0;
		if(!(s[i] = (char **)malloc(sizeof(char *) * 4)))
			return (NULL);
		write(1, "yolo\n", 5);
		while (y < 4)
		{
			write(1, "\tyolo\n", 6);
			if(!(s[i][y] = (char *)malloc(sizeof(char) * 4)))
				return (NULL);
			write(1, "\toloy\n", 6);
			ft_memset(s, 0, 4);
			y++;
		}
		i++;
	}
	s[i_max] = NULL;
	return (s);	
}

int		ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_pow(nb, power - 1));
}
