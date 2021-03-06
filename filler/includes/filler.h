/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin- <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:20:30 by jomeirin-          #+#    #+#            */
/*   Updated: 2016/06/12 12:43:42 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define X_AXIS 1
# define Y_AXIS 2

typedef struct	s_intel
{
	int			half_w;
	int			half_len;
	int			dir_x;
	int			dir_y;
	int			en_quad;
	int			my_quad;
}				t_intel;

typedef struct	s_player
{
	char		player;
	int			x;
	int			y;
}				t_player;

typedef struct	s_object_table
{
	t_player	me;
	t_player	enemy;
	char		**data;
	int			width;
	int			len;
	int			star_count;
}				t_data;

int				find_str(char *big, char *little);
void			playing(t_data *board, t_data *piece, int to);
int				get_next_line(const int fd, char **line);
char 			get_player(char *line);
int				get_stream(int from, int to);

#endif
