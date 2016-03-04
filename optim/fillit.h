/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yolo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:36:34 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/02 14:12:16 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

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

//main and display
int display(int opt);

//helpers.c

int explain_program();
int ft_triplemalloc(char ***s, int i_max, int y_max, int x_max);

//read.c

int read_fillit(int fd, char *buff);
int get_tetros(char *buff, int n);

//solve.c
int xor_tetro(int x, int y, char **te);
int place(int current);
int solve();
void place_piece(int current, int x, int y);
void erase_piece(int current, int x, int y);
int find_place(int *x, int *y, int current);

//tetros_to_left.c
int get_empty_lines(int p);
int get_empty_columns(int p);
void move_left(int p, int c);
void move_up(int p, int l);
int rearrange_tetros(void);

//verify_neighbors.c
int check_tetros(char *buff, int p);
int get_neighbours(int p, int l, int i);
int get_cohesion(int p);

#endif
