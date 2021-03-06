/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:51:53 by jomeirin          #+#    #+#             */
/*   Updated: 2016/10/28 12:51:56 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_mix(double x, double y, double a)
{
	return (x * (1 - a) + y * a);
}
