/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 12:23:49 by simzam            #+#    #+#             */
/*   Updated: 2016/06/05 11:05:25 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1600
# define HEIGHT 900
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_img
{
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				nbyte_img_line;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**array;
	int				length;
	int				width;
	double			scale;
	int				x;
	int				y;
	int				z;
	int				z_max;
	int				z_min;
	double			z_mid;
	double			x_offset;
	double			y_offset;
	double			x_origin;
	double			y_origin;
	double			height;
	int				**colour;
	int				colour_numeric;
	int				tpro;
	int				wire;
	double			tilt1;
	double			tilt2;
	double			tilt3;
	double			tilt4;
	t_img			img;
	double			pasx;
	double			pasy;
	double			pasy1;
	double			pasy2;
	double			pasz;
	double			pasz1;
	double			pasz2;
}					t_env;

typedef struct		s_colour
{
	int				clr_one;
	int				clr_two;
}					t_colour;

typedef struct		s_coordinates
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_matrix_coordinates
{
	t_coord			p1;
	t_coord			p2;
	t_coord			p3;
	t_coord			p4;
}					t_mcoord;

t_env				init_env(int length, int width, int **array, int **colour);
int					**extract_colour(int argc, char **argv);
void				para_view(t_env *e);
void				iso_view(t_env *e);
void				isof_view(t_env *e);
void				pixel_put(t_env *e, int x, int y, int colour);
void				line(t_env *e, t_coord *c1, t_coord *c2);
void				display_tab(int **array, int length,
		int width, int **colour);

t_env				*revarray(t_env *e, int sens);

int					get_colour(t_env *e, double z);
void				draw_triangle(t_coord *p1, t_coord *p2,
		t_coord *p3, t_env *e);
void				horline(t_env *e, t_coord *p1, t_coord *p2, int x);
int					key_event(t_env *e, int keycode);
void				display_param(t_env *e);

#endif
