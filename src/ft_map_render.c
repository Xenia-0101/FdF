/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:32:25 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/17 15:56:50 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void ft_map_render(t_glib *glib)
{
	printf("Rendering map...\n");
	t_map *map = glib->map;
	int i;
	int j;

	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			map->coors[i][j].x = map->coors[i][j].x * map->step_xy + (glib->x / 2);
			map->coors[i][j].y = map->coors[i][j].y * map->step_xy + (glib->y / 2);
			map->coors[i][j].z = map->coors[i][j].z;
			j++;
		}
		i++;
	}
	printf("first point x y: %.1f %.1f\n", map->coors[0][0].x, map->coors[0][0].y);
	printf("mid point x y: %.1f %.1f\n", map->coors[map->rc/2][map->rl/2].x, map->coors[map->rc/2][map->rl/2].y);
	printf("last point x y: %.1f %.1f\n", map->coors[(map->rc)-1][(map->rl)-1].x, map->coors[(map->rc)-1][(map->rl)-1].y);
	printf("\n");
}