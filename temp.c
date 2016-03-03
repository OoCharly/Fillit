/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:51:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:38 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_tetros(char *buff, int n)
{
	int	i;
	int	p;

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

int		check_tetros(char *buff, int p)
{
	int	i;
	int	l;

	i = -1;
	l = 0;
	while (l != 4 && buff[++i])
	{
		while (((i % 5) != 4) && buff[i])
		{
			if (buff[i] == '#')
			{
				g_tetros.tets[p][l][i % 5] = 'A' + p;
				i++;
			}
			else if (buff[i] == '.')
				i++;
			else
				return (0);

		}
		if (buff[i] != '\n')
			return (0);
		l++;
	}
	return (i);
}
///////////////get_neighbours//////////////////////////
//compte et renvoie le nombre d'éléments voisins de l'élément courant
///////////////////////////////////////////////////////


int		get_neighbours(int p, int l, int i)
{
	int	out;

	out =0;
	if (l != 0)
	{
		if (g_tetros.tets[p][l - 1][i])
			out++;
	}
	if (i != 0)
	{
		if (g_tetros.tets[p][l][i - 1])
			out++;
	}
	if (i != 3)
	{
		if (g_tetros.tets[p][l][i + 1])
			out++;
	}
	if (l != 3)
	{
		if (g_tetros.tets[p][l + 1][i])
			out++;
	}
	return (out);
}
/////////////////////get_cohesion////////////////////
//parcours la piece pour vérifier si toute les piece on au moins un voisin
// et si au moins une piece a au moins 2 voisins
// La fonction renvoie le nombre d'élément dans la pièce.
////////////////////////////////////////////////////
int		get_cohesion(int p)
{
	int	i;
	int	out;
	int	pass;
	int	tmp;

	i = -1;
	out = 0;
	pass = 0;
	while (i++ < 20)
	{
		while ((i % 5) != 4)
		{
			if (g_tetros.tets[p][i / 5][i % 5])
			{
				tmp = get_neighbours(p, i / 5, i % 5);
				if (tmp == 0)
					return (0);
				out ++;
				if (tmp > 1)
					pass = 1;
			}
		}
		i++;
	}
	return (out * pass);
}
