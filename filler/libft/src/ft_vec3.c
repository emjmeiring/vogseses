/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:29:52 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 15:29:58 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3	vecadd(t_vec3 *a, t_vec3 *b)
{
	t_vec3	v;

	v.x = a->x + b->x;
	v.y = a->y + b->y;
	v.z = a->z + b->z;
	return (v);
}

t_vec3	vecprod(t_vec3 *a, t_vec3 *b)
{
	t_vec3	v;

	v.x = a->x * b->x;
	v.y = a->y * b->y;
	v.z = a->z * b->z;
	return (v);
}

t_vec3	vecopx(t_vec3 *a, double x)
{
	t_vec3	v;

	v.x = a->x * x;
	v.y = a->y * x;
	v.z = a->z * x;
	return (v);
}

double	vecdistance(t_vec3 *a, t_vec3 *b)
{
	double	distance;

	distance = sqrt((a->x - b->x) * (a->x - b->x) + \
		(a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z));
	return (distance);
}
