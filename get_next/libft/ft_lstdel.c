/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:45:03 by simzam            #+#    #+#             */
/*   Updated: 2016/05/22 15:41:46 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*keep_track;
	t_list	*tracked;

	if (!alst || !*alst || !del)
		return ;
	tracked = *alst;
	while (tracked)
	{
		keep_track = tracked->next;
		ft_lstdelone(&tracked, del);
		tracked = keep_track;
	}
	*alst = NULL;
}
