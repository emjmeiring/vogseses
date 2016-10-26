/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 07:41:01 by simzam            #+#    #+#             */
/*   Updated: 2016/06/24 07:41:03 by simzam           ###   ########.fr       */
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