/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:10:57 by simzam            #+#    #+#             */
/*   Updated: 2016/06/05 11:08:02 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		get_iso_vert(int x, int y, int z, t_env *e)
{
	t_coord p;

	x *= e->scale / 5;
	y *= e->scale / 5;
	p.x = (e->tilt1 * (x + e->x_offset) + e->tilt2 * y) + e->x_origin;
	p.y = ((e->tilt3) * (x + e->y_offset) - \
			(e->tilt4) * y) - (z * e->height) + e->y_origin;
	p.z = z;
	return (p);
}

void		iso_view(t_env *e)
{
	int			i;
	int			j;
	t_coord		p1;
	t_coord		p2;

	i = -1;
	while (++i < e->width)
	{
		j = e->length;
		while (--j >= 0)
		{
			p1 = get_iso_vert(i, j, e->array[i][j], e);
			if (i < e->width - 1)
			{
				p2 = get_iso_vert(i + 1, j, e->array[i + 1][j], e);
				line(e, &p1, &p2);
			}
			if (j < e->length - 1)
			{
				p2 = get_iso_vert(i, j + 1, e->array[i][j + 1], e);
				line(e, &p1, &p2);
			}
		}
	}
}
