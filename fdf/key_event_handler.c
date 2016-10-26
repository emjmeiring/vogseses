/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:31:54 by simzam            #+#    #+#             */
/*   Updated: 2016/06/05 11:35:12 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_event_ext2(t_env *e, int keycode)
{
	if (keycode == 65460 && e->tilt1 < 1.0)
		e->tilt1 += 0.05;
	else if (keycode == 65457 && e->tilt1 > 0.5)
		e->tilt1 -= 0.05;
	else if (keycode == 65462 && e->tilt2 < 1.0)
		e->tilt2 += 0.05;
	else if (keycode == 65459 && e->tilt2 > 0.5)
		e->tilt2 -= 0.05;
	e->tilt3 = e->tilt1;
	e->tilt4 = e->tilt2 / 2.0;
}

void	key_event_ext(t_env *e, int keycode)
{
	if (keycode == 65361)
	{
		if (e->colour_numeric == 0)
			e->colour_numeric = -4;
		else
			e->colour_numeric = 1;
	}
	else if (keycode == 65363)
	{
		if (e->colour_numeric == 4)
			e->colour_numeric += -4;
		else
			e->colour_numeric += 1;
	}
	else if (keycode == 112 || keycode == 9)
	{
		if (e->tpro == 1)
			e->tpro += -1;
		else
			e->tpro += 1;
	}
	else
		key_event_ext2(e, keycode);
}

int		key_event(t_env *e, int keycode)
{
	if (keycode == 97 || keycode == 0)
		e->x_offset -= 10;
	else if (keycode == 100 || keycode == 2)
		e->x_offset += 10;
	else if (keycode == 119 || keycode == 13)
		e->y_offset -= 30;
	else if (keycode == 115 || keycode == 1)
		e->y_offset += 30;
	else if ((keycode == 65362 || keycode == 126) && e->scale < 150)
		e->scale *= 1.5;
	else if ((keycode == 65364 || keycode == 125) && e->scale / 1.5 > 0.5)
		e->scale /= 1.5;
	else if (keycode == 65453 || keycode == 78)
		e->height -= 1.0;
	else if (keycode == 65451 || keycode == 69)
		e->height += 1.0;
	else if (keycode == 113 || keycode == 12)
		e = revarray(e, 1);
	else if (keycode == 101 || keycode == 14)
		e = revarray(e, -1);
	else
		key_event_ext(e, keycode);
	return (0);
}
