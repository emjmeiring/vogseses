/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 08:56:16 by arnovan-          #+#    #+#             */
/*   Updated: 2016/06/12 16:39:31 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**get_board(int from, t_data *data, char *line)
{
	char		**specs;
	char		**board;
	int			i;
	int			offset;
	int			p;

	i = 0;
	specs = ft_strsplit(line, ' ');
	data->width = ft_atoi(specs[1]);
	data->len = ft_atoi(specs[2]);
	board = (char **)malloc(data->width * sizeof(char *));
	
	if (find_str(line, "Plateau"))
	{
		get_next_line(from, &line);
		offset = 4;
	} else offset = 0;
	while (i < data->width && get_next_line(from, &line) == 1)
	{
	
		// PUT IN A SEPERATE FILE
		
		board[i] = ft_strdup(line + offset);
		if (data->enemy.x == -1 || data->me.x == -1)
		{
			p = 0;
			while (p < data->len)
			{
				if (board[i][p] == data->me.player)
				{
					data->me.x = p;
					data->me.y = i;
				}
				if (board[i][p] == data->enemy.player)
				{
					data->enemy.x = p;
					data->enemy.y = i;
				}
				p++;
			}
		}		
		i++;
		free(line);
	}
	ft_memdel((void **)specs);
	return (board);
}

void		get_player(char *line, t_data *board)
{
	char		*temp;

	temp = ft_strstr(line, "p");
	temp++;
	if (*temp == '1')
	{
		board->me.player = 'O';
		board->enemy.player = 'X';
	}
	else
	{
		board->enemy.player = 'O';
		board->me.player = 'X';
	}
}




void	print(t_data piece)
{
	char *x;
	char *y;

	x = ft_itoa(piece.me.x);
			write(1, &(piece.me.x), 1);
	y = ft_itoa(piece.me.y);
			write(1, &(piece.me.y), 1);
	write(1, x, 2);
	write(1, " ", 1);
	write(1, y, ft_strlen(y));
}



int		get_stream(int from, int to)
{
	char		*line;
	t_data		board;
	t_data		piece;

	board.me.x = -1;
	board.enemy.x = -1;
	line = NULL;
	board.me.player = '\0';
	while (get_next_line(from, &line) == 1) // && *line != '<')
	{
		if (board.me.player == '\0' && find_str(line, "[./"))
		{
			get_player(line, &board);

			//DEBUGGING LINE
			write(to, &(board.me.player), 1);
		}
		if (find_str(line, "Plateau"))
		{
			board.data = get_board(from, &board, line);
		}
//		if (ft_strncmp(line, "Plateau", 2) == 0)
//		{
//			board.data = get_board(from, &board, line);
//		}


		if (find_str(line, "Piece"))
		{
			piece.data = get_board(from, &piece, line);
			playing(&board, &piece);
			print(piece);
		}
	}
//DEBUGGING LINE
	write(to, "******\n", 7);
	return (0);
}
