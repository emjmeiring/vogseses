/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 16:42:31 by jomeirin          #+#    #+#             */
/*   Updated: 2016/05/15 16:42:35 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tracker;
	t_list	*tracked;

	if (alst == NULL)
		return ;
	tracked = *alst;
	while (lst != NULL)
	{
		tracker = lst->next;
		ft_lstdelone(&tracked, del);
		tracked = tracker;
	}
	*alst = NULL;
}
