/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:34:51 by jomeirin          #+#    #+#             */
/*   Updated: 2016/06/12 16:35:21 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define Y_AXIS 1
# define X_AXIS 2

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>



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
}				t_data;

int				find_str(char *big, char *little);
void			playing(t_data *board, t_data *piece);
int				get_next_line(const int fd, char **line);
void 			get_player(char *line, t_data *board);
int				get_stream(int from, int to);

#endif
