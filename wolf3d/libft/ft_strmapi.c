/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 11:20:20 by simzam            #+#    #+#             */
/*   Updated: 2016/06/26 11:20:28 by simzam           ###   ########.fr       */
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
		news = malloc(sizeof(char) * ft_strlen(s));
		while (*(s + (++i)) != '\0')
			*(news + i) = f(i, *(s + i));
		return (news);
	}
	return (NULL);
}
