/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:11:45 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 15:11:47 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*nstr;

	i = -1;
	if (s && f)
	{
		j = ft_strlen((char*)s);
		if ((nstr = (char*)malloc(1 + j * sizeof(char))))
		{
			while (*(s + ++i) != '\0')
				nstr[i] = f(*(s + i));
			*(nstr + i) = '\0';
			return (nstr);
		}
	}
	return (NULL);
}
