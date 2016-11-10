/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 08:24:39 by jomeirin          #+#    #+#             */
/*   Updated: 2016/06/12 12:49:19 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	find_strs(char *big, char *little)
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
		i++;
	}
	return (0);
}

int		quadrant(int x, int y, int w, int l)
{
	int q;
	if (x > w)
	{
		if (y > l)
			q = 4;
		else q = 2;
	}
	else if (y > l)
		q = 3;
	else q = 1;
	return (q);
}

void	direction(int my_quad, t_intel *intel)
{
	if (my_quad == 1)
	{
		intel->dir_x = 1;
		intel->dir_y = 1;
	}else if (my_quad == 2)
	{
		intel->dir_x = -1;
		intel->dir_y = 1;
	}else if (my_quad == 3)
	{
		intel->dir_x = 1;
		intel->dir_y = -1;
	}else if (my_quad == 4)
	{
		intel->dir_x = -1;
		intel->dir_y = -1;
	}
}

int		listener(t_data board, t_intel *intel, char player)
{
	int i;
	int found;

	i = 0;
	found = 0;
	while (i < board.width && !found)
	{
		if (found == 0)
			found += find_strs(&board.data[i][intel->half_len], &player);
		i++;
	}
	i = 0;
	while (i < board.len)
	{
		found += 2 * find_strs(&board.data[intel->half_w][i], &player);
		i++;
	}
	return (found);
}

void	devider(t_data board, t_intel *intel)
{
	intel->half_w = board.width/2;
	intel->half_len = board.len/2;
	intel->en_quad = quadrant(board.enemy.x, board.enemy.y, intel->half_w,
			 intel->half_len);
	intel->my_quad = quadrant(board.me.x, board.me.y, intel->half_w,
			 intel->half_len);
	direction(intel->my_quad, intel);
}

int		place_piece(t_data board, t_data piece, int x, int y)
{
	int i;
	int j;
	int xxx;
	int star;

	i = 0;
	j = 0;
	xxx = 0;
	star = 0;
	while (i < piece.width)
	{
		while (j < piece.len)
		{
			if (piece.data[i][j] == '*' && ft_toupper(board.data[x + i][y + j]) == board.me.player)
			{
				xxx += 1;
				//if ((x + i) < board.width && (y + i) < board.len)
				//	return (1);
			}
			else if (piece.data[i][j] == '*' && board.data[x + i][y + j] == '.')
				star += 1;
			j++;
		}
		i++;
	}
	if (xxx == 1 && (star + xxx) == piece.star_count)
		return (1);
	else
		return (0);
}

void	place_move(t_data *board, t_data *piece, t_intel *intel, int to)
{
	int i;
	int j;
	
	if (intel->dir_x == 1)
	{
		i = board->width - 1;
	}
	else i = 0;
	if (intel->dir_y == 1)
		j = board->len - 1;
	else j = 0;
	
	while (i >= 0 && board->data[i] != '\0')
	{
		while (i >= 0 && j >= 0 && board->data[i][j] != '\0')
		{
			if (place_piece(*board, *piece, i, j))
			{
				write(to, "--", 2);
				piece->me.x = i;
				piece->me.y = j;
				write(to, "\ni=", 3);ft_putnbr_fd(i,to);
				write(to, "\nj=", 3);ft_putnbr_fd(j,to);
				return ;
			}
			j -= intel->dir_y;
		}
		i -= intel->dir_x;
	}
}
void	playing(t_data *board, t_data *piece, int to)
{
	t_intel intel;
	int found_me;
	int found_enemy;

	devider(*board, &intel);
	found_me = listener(*board, &intel, board->me.player);
	found_enemy = listener(*board, &intel, board->enemy.player);
	

ft_putnbr_fd(found_enemy, to);write(to, "<\n", 2);
	ft_putnbr_fd(found_me, to);write(to, "<\n", 2);
	ft_putnbr_fd(intel.half_w, to);write(to, "<\n", 2);
	ft_putnbr_fd(intel.half_len, to);write(to, "<\n", 2);
	ft_putnbr_fd(intel.dir_x, to);write(to, "<\n", 2);
	ft_putnbr_fd(intel.dir_y, to);write(to, "<\n", 2);
	ft_putnbr_fd(intel.en_quad, to);write(to, "<\n", 2);
	ft_putnbr_fd(intel.my_quad, to);write(to, "<\n", 2);
//	printf("%d:\n", found_me);
//	printf("%d:\n", intel.half_w);
//	printf("%d:\n", intel.half_len);
//	printf("%d:\n", intel.dir_x);
//	printf("%d:\n", intel.dir_y);
//	printf("%d:\n", intel.en_quad);
//	printf("%d:\n", intel.my_quad);
	//int i = 0;
	//while (i < piece->width)
	//	printf("%s\n", (piece->data[i++]));

	if (found_enemy == Y_AXIS)
	{
		if (intel.en_quad == 1 || intel.en_quad == 3)
			intel.dir_x = 1;
		else intel.dir_x = -1;
	}else if (found_enemy == X_AXIS)	
	{
		if (intel.en_quad == 1 || intel.en_quad == 2)
			intel.dir_y = 1;
		else intel.dir_y = -1;
	}
	place_move(board, piece, &intel, to);
}
