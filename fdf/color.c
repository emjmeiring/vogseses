/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:30:24 by simzam            #+#    #+#             */
/*   Updated: 2016/06/05 10:58:09 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*putcolor(int a, int b, int c)
{
	int		*colour;

	colour = malloc(sizeof(int) * 3);
	colour[0] = a;
	colour[1] = b;
	colour[2] = c;
	return (colour);
}

int		**extract_colour(int argc, char **argv)
{
	int		**colour;

	colour = malloc(sizeof(int *) * 5);
	if (argc > 4)
	{
		colour[0] = malloc(sizeof(int *) * 3);
		colour[0][0] = ft_atoi(argv[2]);
		colour[0][1] = ft_atoi(argv[3]);
		colour[0][2] = ft_atoi(argv[4]);
	}
	else
		colour[0] = putcolor(0x000000, 0x808080, 0xFFFFFF);
	colour[1] = putcolor(0x0bf0e0, 0xe2c6ff, 0xf3d85e);
	colour[2] = putcolor(0xb9280e, 0x3d231a, 0x27160c);
	colour[3] = putcolor(0x124511, 0x1a0f0f, 0x888181);
	colour[4] = putcolor(0x0000ff, 0x00ff00, 0xff0000);
	return (colour);
}

void	pixel_put(t_env *e, int x, int y, int colour)
{
	int		pos;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * e->img.bpp / 8) + (y * e->img.nbyte_img_line);
		e->img.img[pos] = colour % 256;
		e->img.img[pos + 1] = (colour >> 8) % 256;
		e->img.img[pos + 2] = (colour >> 16) % 256;
	}
}

int		search_a_colour(t_colour *colour, int z, int z_min, int z_max)
{
	int		c1;
	int		c2;
	int		v;

	if (z <= z_min)
		return (colour->clr_one);
	if (z >= z_max)
		return (colour->clr_two);
	c1 = colour->clr_one / 256;
	c2 = colour->clr_two / 256;
	v = ((((z - abs(z_min)) * (c2 - c1)) / \
		(z_max - abs(z_min))) + c1) * 256 * 256;
	c1 = colour->clr_one / 256 % 256;
	c2 = colour->clr_two / 256 % 256;
	v += ((((z - abs(z_min)) * (c2 - c1)) / (z_max - abs(z_min))) + c1) * 256;
	c1 = colour->clr_one % 256;
	c2 = colour->clr_two % 256;
	v += ((((z - abs(z_min)) * (c2 - c1)) / (z_max - abs(z_min))) + c1);
	return (v);
}

int		get_colour(t_env *e, double z)
{
	t_colour		colour;

	if (z < e->z_min || z > e->z_max)
		return (0);
	if (z <= e->z_mid && z >= e->z_min)
	{
		colour.clr_one = e->colour[e->colour_numeric][0];
		colour.clr_two = e->colour[e->colour_numeric][1];
		return (search_a_colour(&colour, z, e->z_min, e->z_mid));
	}
	else if (z <= e->z_max && z >= e->z_mid)
	{
		colour.clr_one = e->colour[e->colour_numeric][1];
		colour.clr_two = e->colour[e->colour_numeric][2];
		return (search_a_colour(&colour, z, e->z_mid, e->z_max));
	}
	return (0);
}
