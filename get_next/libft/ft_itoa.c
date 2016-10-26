/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 16:37:03 by jomeirin          #+#    #+#             */
/*   Updated: 2016/05/15 16:37:23 by goisetsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;

	if (n > 2147483647 || n < -2147483647)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char *))))
		return (NULL);
	if (n >= 0)
	{
		while (n != 0)
		{
			*(--str) = '0' + (n % 10);
			n /= 10;
		}
		return (str);
	}
	else
	{
		while (n != 0)
		{
			*(--str) = '0' - (n % 10);
			n /= 10;
		}
		*(--str) = '-';
	}
	return (str);
}
