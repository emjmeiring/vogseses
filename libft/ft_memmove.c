/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:50:53 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 12:50:55 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*c1;
	const char	*c2;

	c2 = src;
	c1 = dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	c2 += len;
	c1 += len;
	while (len--)
		*--c1 = *--c2;
	return (dst);
}
