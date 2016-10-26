/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:37:42 by jomeirin          #+#    #+#             */
/*   Updated: 2016/06/12 16:37:49 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

void	load_data(int from, int to)
{
	to = open("debug.log", O_WRONLY | O_CREAT | O_APPEND, 0666);
	// 	Testing from file input
//	from = open("test3.txt", O_RDONLY | O_CREAT | O_APPEND, 0666);
	get_stream(from, to);
	
}

int		main(void) 
{
	static int		to;
	static int		from;

	load_data(from, to);
	close(from);
	close(to);
	return 0;
}

