/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:03:27 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/07 18:03:45 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// loop through map->coors and display each point on the map
void ft_draw_points(t_glib *glib, t_map *map)
{
	int i;
	int j;
	int point[3];

	i = 0;
	// printf("%d\n", map->rc);
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			point[0] = map->coors[i][j].x;
			point[1] = map->coors[i][j].y;
			point[2] = map->coors[i][j].z;
			ft_put_points_3d(glib, point);
			j++;
		}
		i++;
	}
}
