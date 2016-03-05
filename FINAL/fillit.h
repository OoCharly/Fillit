/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:52:27 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/05 13:06:05 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_tetros
{
	char		***tets;
	int			tot;
}				t_tetros;

typedef struct	s_grid
{
	char		**tab;
	int			len;
}				t_grid;

t_grid			g_grid;
t_tetros		g_tetros;

int				explain_program();
char			***ft_triplemalloc(int i_max);
int				ft_pow(int nb, int power);

int				read_fillit(int fd, char *buff);
int				get_tetros(char *buff, int n);

int				place(int current);

int				rearrange_tetros(void);

int				check_tetros(char *buff, int p);
int				get_cohesion(int p);

void			ft_putstr(char *str);

#endif
