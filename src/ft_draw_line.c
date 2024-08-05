/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:49:05 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/05 18:43:12 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static int *ft_get_point(t_map *map, int i, int j, int point[3])
// {
// 	int x = map->coors[i][j].x;
// 	int y = map->coors[i][j].y;
// 	int z = map->coors[i][j].z;

// 	point[0] = x * cos(120) + y * cos(122) + z * cos(118);
// 	point[1] = x * sin(120) + y * sin(122) + z * sin(118);
// 	point[2] = 0;
// 	return (point);
// }


static void ft_draw_h(t_glib *glib, t_map *map)
{
	int p1[2];
	int p2[2];
	int i;
	int j;

	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl - 1)
		{
			p1[0] = map->coors_tr[i][j].x;
			p1[1] = map->coors_tr[i][j].y;
			p2[0] = map->coors_tr[i][j+1].x;
			p2[1] = map->coors_tr[i][j+1].y;
			ft_bresenham(glib, p1, p2);
			j++;
		}
		i++;
		// printf("***%d\n", i);
	}
}

static void ft_draw_v(t_glib *glib, t_map *map)
{
	int p1[3];
	int p2[3];
	int i;
	int j;

	i = 0;
	while (i < map->rc - 1)
	{
		j = 0;
		while (j < map->rl)
		{
			p1[0] = map->coors_tr[i][j].x;
			p1[1] = map->coors_tr[i][j].y;
			p2[0] = map->coors_tr[i+1][j].x;
			p2[1] = map->coors_tr[i+1][j].y;
			ft_bresenham(glib, p1, p2);
			j++;
		}
		i++;
		// printf("***%d\n", i);
	}
}

void ft_draw_line(t_glib *glib, t_map *map)
{
	ft_draw_v(glib, map);
	ft_draw_h(glib, map);
}