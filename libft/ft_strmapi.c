/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:11:58 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 15:12:00 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*news;

	i = -1;
	if (s && f)
	{
		if ((news = malloc(sizeof(char) * ft_strlen(s) + 1)))
		{
			while (*(s + (++i)) != '\0')
				*(news + i) = f(i, *(s + i));
			*(news + i) = '\0';
			return (news);
		}
	}
	return (NULL);
}
