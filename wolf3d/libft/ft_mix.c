/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 07:40:09 by simzam            #+#    #+#             */
/*   Updated: 2016/06/24 07:40:11 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_mix(double x, double y, double a)
{
	return (x * (1 - a) + y * a);
}
