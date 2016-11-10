/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:35:26 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 12:35:29 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *blist)
{
	int		i;
	t_list	*list;

	i = 0;
	if (blist)
	{
		list = blist;
		while (list)
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}
