/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:23:21 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/11 10:28:12 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Allocate memory for map->coors_tr (Transformed coordinates)
// Requires map->rl and map->rc values to be set correctly
static void ft_coors_tr_allocate(t_map *map)
{
	int i;

	map->coors_tr = (t_point_d **)ft_calloc(map->rc + 1, sizeof (t_point_d *));
	if (map->coors_tr == NULL)			// TODO: Error handling
	{
		return ;		// ToDo: Exit safely
	}
	i = 0;
	while (i < map->rc)
	{
		map->coors_tr[i] = (t_point_d *)ft_calloc(map->rl + 1, sizeof (t_point_d));
		i++;
	}
}

// shift x and y coors into positive numbers and into the middle of the image
void ft_map_shift(t_glib *glib)
{
	t_map *map;
	int i;
	int j;
	double mid_x;
	double mid_y;

	map = glib->map;
	ft_coors_tr_allocate(map);
	mid_x = map->coors[map->rc / 2][map->rl / 2].x * map->step_xy;
	mid_y = map->coors[map->rc / 2][map->rl / 2].y * map->step_xy;

	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			map->coors[i][j].x = map->coors[i][j].x * map->step_xy + map->step_x + (glib->x_size / 2 - mid_x);
			map->coors[i][j].y = map->coors[i][j].y * map->step_xy + map->step_y + (glib->y_size / 2 - mid_y);
			map->coors_tr[i][j].x = map->coors[i][j].x;
			map->coors_tr[i][j].y = map->coors[i][j].y;
			j++;
		}
		i++;
	}
	printf("|  %5.1f %5.1f  |\n", map->coors[0][18].x, map->coors[0][18].y);
}