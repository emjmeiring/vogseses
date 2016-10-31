/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:04:02 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/31 11:42:34 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	int		len;

	len = -1;
	while (s1[++len])
		;
	if ((c = (char *)malloc(len * sizeof(char) + 1)))
	{
		if (c != NULL)
			ft_strcpy(c, s1);
		*(c + len) = '\0';
	}
	return (c);
}
