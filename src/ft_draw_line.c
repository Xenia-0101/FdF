/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:49:05 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/05 14:10:39 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int *ft_get_point(t_map *map, int i, int j, int point[3])
{
	int x = map->coors[i][j].x;
	int y = map->coors[i][j].y;
	int z = map->coors[i][j].z;

	point[0] = x * cos(120) + y * cos(122) + z * cos(118);
	point[1] = x * sin(120) + y * sin(122) + z * sin(118);
	point[2] = 0;
	return (point);
}

static void ft_draw_h(t_glib *glib, t_map *map)
{
	int p1[3];
	int p2[3];
	int i;
	int j;

	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl - 1)
		{
			ft_bresenham(glib, ft_get_point(map, i, j, p1), ft_get_point(map, i, j + 1, p2));
			j++;
		}
		i++;
		printf("***%d\n", i);
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
			ft_bresenham(glib, ft_get_point(map, i, j, p1), ft_get_point(map, i + 1, j, p2));
			j++;
		}
		i++;
		printf("***%d\n", i);
	}
}

void ft_draw_line(t_glib *glib, t_map *map)
{
	ft_draw_v(glib, map);
	ft_draw_h(glib, map);
}