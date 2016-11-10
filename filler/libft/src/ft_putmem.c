/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:54:38 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 12:54:42 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(void *mem, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		ft_putchar((*(unsigned char *)mem) + i);
}