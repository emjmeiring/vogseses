/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin- <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:18:09 by jomeirin-         #+#    #+#             */
/*   Updated: 2016/06/12 12:51:09 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	find_str(char *big, char *little)
{
	int	i;
	int	j;

	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i] == little[j])
		{
			if (little[j + 1] == '\0')
				return (1);
			i++;
			j++;
		}
		i = i - j; //This might just be redudant.
		i++;
	}
	return (0);
}

char	**get_board(int from, t_data *data, char *line, int to)
{
	char		**specs;
	char		**board;
	int			i;
	int			offset;

	i = 0;
	specs = ft_strsplit(line, ' ');
	data->width = atoi(*(specs + 1));
	data->len = atoi(*(specs + 2));
	board = (char **)malloc(data->width * sizeof(char *));
	
	if (ft_strncmp(line, "Platua", 2) == 0)
	{
		get_next_line(from, &line);
		write(to, line, ft_strlen(line));
		write(to, "\n", 1);
		offset = 4;
	} else offset = 0;
	while (i < data->width && get_next_line(from, &line) == 1)
	{
	//write(0, "ass", 3);
		write(to, line, ft_strlen(line));
		write(to, "\n", 1);
		board[i] = ft_strdup(line + offset);
		i++;
		free(line);
	}
	ft_memdel((void **)specs);
	return (board);
}

char		get_player(char *line)
{
	char		*temp;

	temp = ft_strstr(line, "p");
	temp++;
	if (*temp == '1')
		return ('O');
	else return ('X');
}

void	print(t_data piece, int to)
{
	char *x;
	char *y;

	//write(to, "myne\n", 5);
	int a = piece.me.x;
	int b = piece.me.y;
	x = ft_itoa(piece.me.x);
	y = ft_itoa(piece.me.y);
	write(1, x, ft_strlen(x));
	write(1, "   ", 1);
	write(1, y, ft_strlen(y));
	write(1, "\n", 1);write(to, "[", 1);
	write(to, x, ft_strlen(x));
	write(to, "   ", 1);
	write(to, y, ft_strlen(y));write(to, "]", 1);
}

void	count_stars(t_data *piece)
{
	int i;
	int j;

	i = 0;
	j = 0;
	piece->star_count = 0;
	while (i < piece->width)
	{
		while (j < piece->len)
		{
			if (piece->data[i][j] == '*')
				piece->star_count += 1;
			j++;
		}
		i++;
	}
}

int		get_stream(int from, int to)
{
	char		*line;
	//char		*r;
	//int			i;
	t_data		board;
	t_data		piece;
	
	line = NULL;

	board.me.player = '\0';
	piece.me.x = 0;
	piece.me.y = 0;
	while (get_next_line(from, &line) == 1)
	{
		//i++;
		write(to, line, ft_strlen(line));
		write(to, "\n", 1);
		if (board.me.player == '\0' && find_str(line, "/filler"))
		{
			board.me.player = get_player(line);
			//write(to, line, ft_strlen(line));
			//write(0, "ass", 3);
		}
		//printf("This is the player: %s\n", line);
		if (ft_strncmp(line, "Platua", 2) == 0)
		{
		//write(0, "ass", 3);
			board.data = get_board(from, &board, line, to);
			//write(0, "ass", 3);
			//i = -1;
			//while (i++ < board.width)
			//{
			//	write(to, board.data[i], ft_strlen(board.data[i]));
			//	write(to, "\n", 1);
			//}

		}
		//i = 0;
		//write(to, "ass", 3);
		if (ft_strncmp(line, "Piece", 2) == 0)
		{
			//write(to, "ass1", 4);
			piece.data = get_board(from, &piece, line, to);
			count_stars(&piece);
			//i = -1;
			//while (i++ < piece.width)
			//{
			//	write(to, piece.data[i], ft_strlen(piece.data[i]));
			//	write(to, "\n", 1);
			//}
			playing(&board, &piece, to);
			print(piece, to);
			
		}
		//write(to, line, ft_strlen(line));
		//write(to, "\n", 1);
	}
	return (0);
}
