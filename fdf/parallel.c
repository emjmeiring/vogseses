/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:11:27 by simzam            #+#    #+#             */
/*   Updated: 2016/06/05 11:31:39 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		para_view_vert(int x, int y, int z, t_env *e)
{
	t_coord		p;

	x *= e->scale;
	y *= e->scale;
	p.y = (x + e->y_offset) + e->tilt1 * -z + e->y_origin;
	p.x = (y + e->x_offset) + e->tilt3 * (-z * e->height) + e->x_origin;
	p.z = z;
	return (p);
}

void		para_view(t_env *e)
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
			p1 = para_view_vert(i, j, e->array[i][j], e);
			if (i < e->width - 1)
			{
				p2 = para_view_vert(i + 1, j, e->array[i + 1][j], e);
				line(e, &p1, &p2);
				if (j < e->length - 1)
				{
					p2 = para_view_vert(i, j + 1, e->array[i][j + 1], e);
					line(e, &p1, &p2);
				}
			}
		}
	}
}
