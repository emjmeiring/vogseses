/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:23:15 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 15:23:22 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;

	i = -1;
	news = malloc(sizeof(char) * len + 1);
	if (!news || !len || !s)
		return (NULL);
	while (++i < len)
		*(news + i) = *(s + start + i);
	*(news + i) = '\0';
	return (news);
}
