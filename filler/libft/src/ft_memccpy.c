/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:41:43 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 12:41:46 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char 	seg_test;
	
	i = 0;
	while (*((char *)src + i) != '\0')
		i += 1;
	seg_test = *((char *)dst + n - 1);
	seg_test = *((char *)dst + i);
	seg_test = *((char *)src + n - 1);
	i = 0;
	if (dst && src && c && n)
	{
		while (i < n)
		{
			*((char *)dst + i) = *((char *)src + i);
			if (*((char *)src + i) == (char)c)
			{
				return ((char *)dst + i + 1);
			}
			i++;
		}
	}
	return (NULL);
}
