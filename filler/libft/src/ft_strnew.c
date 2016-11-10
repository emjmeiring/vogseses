/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:44:35 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 15:44:37 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = -1;
	new = malloc(sizeof(char) * (++size));
	if (!new)
		return (NULL);
	while (++i < size)
		*(new + i) = '\0';
	return (new);
}
