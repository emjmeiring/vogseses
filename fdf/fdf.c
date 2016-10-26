/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:54:19 by simzam            #+#    #+#             */
/*   Updated: 2016/06/02 13:56:19 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*get_lstfile(int fd, int **len)
{
	char	*line;
	t_list	*list;

	line = NULL;
	list = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		**len = ft_strlen(line);
		ft_lstpushback(&list, line, **len);
	}
	return (list);
}

int		ft_tablen(char **array)
{
	int		x;

	x = 0;
	while (*(array + x))
		x++;
	return (x);
}

int		*put_array(char **line, int **len)
{
	int		i;
	int		y;
	int		*actual_val;

	i = -1;
	y = ft_tablen(line);
	if (y < **len)
		**len = y;
	actual_val = malloc(sizeof(int) * y);
	while (++i < y)
		actual_val[i] = ft_atoi(line[i]);
	return (actual_val);
}

int		**get_array(int fd, int *len, int *wid)
{
	int		**array;
	char	**line;
	t_list	*list;
	int		x;

	x = -1;
	list = get_lstfile(fd, &len);
	if (!list)
		exit(0);
	array = malloc(sizeof(int *) * ft_lstlen(list));
	while (list)
	{
		line = ft_strsplit(list->content, ' ');
		array[++x] = put_array(line, &len);
		list = list->next;
	}
	*wid = x + 1;
	return (array);
}

int		main(int ac, char **av)
{
	int		fd;
	int		**array;
	int		len;
	int		wid;
	int		**colour;

	len = 0;
	wid = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (0);
		array = get_array(fd, &len, &wid);
		close(fd);
		colour = extract_colour(ac, av);
		if (array)
			display_tab(array, len, wid, colour);
		return (0);
	}
	return (-1);
}
