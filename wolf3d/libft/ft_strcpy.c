/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 11:17:29 by simzam            #+#    #+#             */
/*   Updated: 2016/06/26 11:17:34 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	length;
	size_t	index;

	length = ft_strlen(src);
	index = -1;
	while (++index <= length && src[index] != '\0')
		*(dst + index) = *(src + index)
				;
	dst[index] = '\0';
	return (dst);
}
