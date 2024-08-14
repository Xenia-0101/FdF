/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:53:06 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/14 18:20:24 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_get_colour(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a );
}

void ft_put_point(t_glib *glib, int p[2])
{
	int c = ft_get_colour(0, 0,255,255);
	if ((p[0] > 1 && p[1] > 1) && !(p[0] > glib->x || p[1] > glib->y))
		mlx_put_pixel(glib->img, p[0], p[1], c);
}

void ft_reset_img(t_glib *glib)
{
	printf("resetting img...\n");
	memset(glib->img->pixels, 0xFF, glib->img->width * glib->img->height * sizeof (int32_t));
}
