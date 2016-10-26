/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 11:18:10 by simzam            #+#    #+#             */
/*   Updated: 2016/06/26 11:18:12 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;

	i = -1;
	news = malloc(sizeof(char) * len);
	if (!news || !len || !s)
		return (NULL);
	while (++i < len)
		*(news + i) = *(s + start + i);
	return (news);
}
