/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:32:18 by simzam            #+#    #+#             */
/*   Updated: 2016/06/05 08:51:05 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_fill_image(t_env *e)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			pixel_put(e, x, y, 0x000000);
		}
	}
}

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_fill_image(e);
	if (e->tpro == 0 && e->wire == 0)
		iso_view(e);
	else if (e->tpro == 1)
		para_view(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307 || keycode == 53)
		exit(1);
	else
		key_event(e, keycode);
	expose_hook(*&e);
	return (0);
}

void	display_tab(int **array, int length, int width, int **color)
{
	t_env	e;

	e = init_env(length, width, array, color);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
