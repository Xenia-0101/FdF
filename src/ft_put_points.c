/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:53:06 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/04 14:56:10 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void ft_put_points_3d(t_glib *glib, int p[3])
{
	double px = p[0] * cos(120) + p[1] * cos(122) + p[2] * cos(118);
	double py = p[0] * sin(120) + p[1] * sin(122) + p[2] * sin(118);
	if (px > 0 && py > 0)
		mlx_put_pixel(glib->img, px, py, 0);
	printf("PUT POINTS 3D: %f %f\n", px, py);
}

void ft_put_points_2d(t_glib *glib, int p[2])
{
	if (p[0] > 0 && p[1] > 0)
		mlx_put_pixel(glib->img, p[0], p[1], 0);
	printf("\t%d %d\n", p[0], p[1]);
}
