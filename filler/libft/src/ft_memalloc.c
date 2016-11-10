/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:41:26 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 12:41:28 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = -1;
	mem = malloc(sizeof(size_t) * size);
	if (!mem)
		return (NULL);
	while (++i < size)
		*((unsigned char *)mem + i) = '\0';
	return (mem);
}
