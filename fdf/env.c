/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:34:16 by simzam            #+#    #+#             */
/*   Updated: 2016/06/02 12:31:37 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "The Honey Bagder");
	e->img.img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img.img = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp, \
									&e->img.nbyte_img_line, &e->img.endian);
}

t_env	board_bounds(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	e->z_min = e->array[0][0];
	e->z_max = e->z_min;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
		{
			if (e->array[i][j] > e->z_max)
				e->z_max = e->array[i][j];
			if (e->array[i][j] < e->z_min)
				e->z_min = e->array[i][j];
		}
	}
	return (*e);
}

t_env	turn_table(t_env *e)
{
	int		i;
	int		j;

	if (e->z_min >= 0)
		return (*e);
	i = -1;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
			e->array[i][j] += -e->z_min;
	}
	e->z_max += -e->z_min;
	e->z_min = 0;
	return (*e);
}

t_env	init_env(int length, int width, int **array, int **colour)
{
	t_env e;

	e.x_offset = 0;
	e.y_offset = 0;
	e.x_origin = 0;
	e.y_origin = 0;
	e.array = array;
	e.length = length;
	e.width = width;
	e.height = 2;
	e.tpro = 0;
	e.wire = 0;
	e = board_bounds(&e);
	e = turn_table(&e);
	e.colour = colour;
	e.colour_numeric = 1;
	e.z_mid = (e.z_min + e.z_max) / 2.0;
	e.scale = ((double)(WIDTH + HEIGHT) / 2.0) / \
				((double)(e.width + e.length) / 2.0);
	e.tilt1 = 0.66;
	e.tilt2 = 0.66;
	e.tilt3 = e.tilt1 / 2.0;
	e.tilt4 = e.tilt2 / 2.0;
	init_img(&e);
	return (e);
}
