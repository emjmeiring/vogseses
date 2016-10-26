/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:25:39 by simzam            #+#    #+#             */
/*   Updated: 2016/06/05 11:01:37 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_right_h(t_env *e, t_coord *p1, t_coord *p2)
{
	int		x;
	double	z;

	x = p1->x - 1;
	z = p1->z;
	while (++x <= p2->x)
	{
		pixel_put(e, x, p1->y + ((p2->y - p1->y) * (x - p1->x)) / \
			(p2->x - p1->x), get_colour(e, z));
		z += e->pasz;
	}
}

void	draw_left_h(t_env *e, t_coord *p1, t_coord *p2)
{
	int		x;
	double	z;

	x = p1->x - 1;
	z = p2->z;
	while (++x <= p1->x)
	{
		pixel_put(e, x, p2->y + ((p1->y - p2->y) * (x - p2->x)) / \
			(p1->x - p2->x), get_colour(e, z));
		z += e->pasz;
	}
}

void	draw_up_v(t_env *e, t_coord *p1, t_coord *p2)
{
	int		y;
	double	z;

	y = p2->y - 1;
	z = p2->z;
	while (++y <= p1->y)
	{
		pixel_put(e, p2->x + ((p1->x - p2->x) * (y - p2->y)) / \
			(p1->y - p2->y), y, get_colour(e, z));
		z += e->pasz;
	}
}

void	draw_down_v(t_env *e, t_coord *p1, t_coord *p2)
{
	int		y;
	double	z;

	y = p1->y - 1;
	z = p1->z;
	while (++y <= p2->y)
	{
		pixel_put(e, p1->x + ((p2->x - p1->x) * (y - p1->y)) / \
			(p2->y - p1->y), y, get_colour(e, z));
		z += e->pasz;
	}
}

void	line(t_env *e, t_coord *p1, t_coord *p2)
{
	if (fabs(p2->x - p1->x) > fabs(p2->y - p1->y))
		e->pasz = (p2->z - p1->z) / (p2->x - p1->x);
	else
		e->pasz = (p2->z - p1->z) / (p2->y - p1->y);
	if (p1->x <= p2->x && (p2->x - p1->x) >= fabs(p2->y - p1->y))
		draw_right_h(e, p1, p2);
	else if (p2->x <= p1->x && (p1->x - p2->x) >= fabs(p1->y - p2->y))
		draw_left_h(e, p1, p2);
	else if (p2->y <= p1->y && (p1->y - p2->y) >= fabs(p1->x - p2->x))
		draw_up_v(e, p1, p2);
	else if (p1->y <= p2->y && (p2->y - p1->y) >= fabs(p2->x - p1->x))
		draw_down_v(e, p1, p2);
}
