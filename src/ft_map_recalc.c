/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_recalc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:02:03 by xenia             #+#    #+#             */
/*   Updated: 2024/08/17 20:02:25 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void ft_manipulate_img(t_glib *glib, char o, float v)
{
	if (o == 'x')
		glib->map->dd.dx += v;
	if (o == 'y')
		glib->map->dd.dy += v;
	if (o == '+')
		glib->map->dd.dxy += v;
	if (o == 'z')
		glib->map->dd.dz += v;
	if (o == 'a')
		glib->map->ax += v;
	if (o == 'w')
		glib->map->ay += v;
	if (o == 'q')
		glib->map->axy += v;
	ft_map_transform(glib);
	memset(glib->img->pixels, 0x00, glib->img->width * glib->img->height * sizeof (int32_t));
	ft_draw(glib, glib->map);
}

