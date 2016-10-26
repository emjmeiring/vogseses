/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:30:49 by simzam            #+#    #+#             */
/*   Updated: 2016/06/02 12:30:53 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**tabmalloc(int x, int y)
{
	int		i;
	int		**array;

	i = -1;
	array = malloc(sizeof(int *) * x);
	while (++i < x)
		array[i] = malloc(sizeof(int *) * y);
	return (array);
}

t_env	*revarray(t_env *e, int sens)
{
	int		i;
	int		j;
	int		**newtab;

	newtab = tabmalloc(e->length, e->width);
	i = -1;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
		{
			if (sens == 1)
				newtab[e->length - (j + 1)][i] = e->array[i][j];
			else
				newtab[j][e->width - (i + 1)] = e->array[i][j];
		}
	}
	i = e->width;
	e->width = e->length;
	e->length = i;
	free(e->array);
	e->array = newtab;
	return (e);
}
