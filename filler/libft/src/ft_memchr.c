/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:42:04 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 12:42:07 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*p;
	char			seg_test;

	i = 0;
	seg_test = *((char *)s);
	p = (unsigned char*)s;
	if (s && n > 0)
		while (i < n)
		{
			if (p[i] == (unsigned char)c)
				return ((void*)(p + i));
			i++;
		}
	return (NULL);
}
