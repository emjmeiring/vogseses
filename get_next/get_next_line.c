/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:35:24 by jomeirin          #+#    #+#             */
/*   Updated: 2016/05/22 18:09:22 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	buff_line(char **line, char *buffer)
{
	char	*buff_mem;
	int		length;

	length = ft_strlen(*line) + ft_strlen(buffer);
	buff_mem = ft_strnew(length);
	buff_mem = ft_strcpy(buff_mem, *line);
	buff_mem = ft_strncat(buff_mem, buffer, length);
	ft_memdel((void **)line);
	*line = ft_strcpy(ft_strnew(length), buff_mem);
}

int		get_next_line(const int fd, char **line)
{
	size_t		pos;
	int			nbytes;
	char		*buffer;

	pos = 0;
	buffer = ft_strnew(BUFF_SIZE);
	ft_memset(*line, '\0', ft_strlen(*line));
	nbytes = read(fd, (buffer + pos), 1);
	while (*(buffer + pos) != '\n' && nbytes > 0)
	{
		pos++;
		if (BUFF_SIZE == pos)
		{
			buff_line(line, buffer);
			pos = 0;
		}
		if ((nbytes = read(fd, (buffer + pos), 1)) == -1)
			return (-1);
	}
	if (nbytes != 0)
		*(buffer + pos) = '\0';
	buff_line(line, buffer);
	free(buffer);
	return (nbytes);
}
