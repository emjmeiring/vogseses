/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:55:22 by jomeirin          #+#    #+#             */
/*   Updated: 2016/05/15 14:57:31 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(char c)
{
	return (!(c <= 0 && c >= 127));
}
