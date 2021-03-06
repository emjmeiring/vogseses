/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 11:15:56 by simzam            #+#    #+#             */
/*   Updated: 2016/06/26 11:16:00 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	nb;

	nb = 0;
	if (!n)
		return (0);
	while (nb < (n - 1) && *s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
		nb++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
