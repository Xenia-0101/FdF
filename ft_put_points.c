/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:53:06 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/01 19:53:27 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void ft_put_points(t_map *map, int p[3])
{
	double px = p[0] * cos(120) + p[1] * cos(122) + p[2] * cos(118);
	double py = p[0] * sin(120) + p[1] * sin(122) + p[2] * sin(118);
	if (px > 0 && py > 0)
		mlx_put_pixel(map->img, px, py, 0);
	// printf("\t%f %f\n", px, py);
}