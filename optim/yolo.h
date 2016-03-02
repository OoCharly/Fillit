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
