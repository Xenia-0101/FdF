/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:53:06 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/05 16:54:01 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_get_colour(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void ft_put_points_3d(t_glib *glib, int p[3])
{
	double px = p[0] * cos(120) + p[1] * cos(122) + p[2] * cos(118);
	double py = p[0] * sin(120) + p[1] * sin(122) + p[2] * sin(118);

	if (px > 0 && py > 0)
		mlx_put_pixel(glib->img, px, py, 255);
	// printf("PUT POINTS 3D: %f %f\n", px, py);
}

void ft_put_points_2d(t_glib *glib, int p[2])
{
	if (p[0] > 0 && p[1] > 0)
		mlx_put_pixel(glib->img, p[0], p[1], ft_get_colour(171,219,227));
	// printf("\t%d %d\n", p[0], p[1]);
}
