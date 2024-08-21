/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_recalc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:02:03 by xenia             #+#    #+#             */
/*   Updated: 2024/08/21 10:36:55 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_recalc(t_glib *glib, char o, float v)
{
	if (o == '7')
		glib->oa += v;
	if (o == '4')
		glib->ob += v;
	if (o == '1')
	{
		if (glib->proj == 1)
			glib->proj = 2;
		else
			glib->proj = 1;
	}
}

void	ft_map_recalc(t_glib *glib, char o, float v)
{
	int32_t	size;

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
	ft_recalc(glib, o, v);
	ft_map_transform(glib);
	size = glib->img->width * glib->img->height * sizeof (int32_t);
	memset(glib->img->pixels, 0x00, size);
	ft_map_draw(glib);
}
