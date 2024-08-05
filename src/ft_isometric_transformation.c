/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric_transformation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:39:14 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/05 18:54:20 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static double *ft_transform(t_map *map, double p[3], int i, int j)
{
	int x;
	int y;
	int z;

	x = map->coors[i][j].x;
	y = map->coors[i][j].y;
	z = map->coors[i][j].z;
	p[0] = x * cos(120) + y * cos(122) + z * cos(118);
	p[1] = x * sin(120) + y * sin(122) + z * sin(118);
	p[2] = 0;
	map->coors_tr[i][j].x = p[0];
	map->coors_tr[i][j].y = p[1];
	map->coors_tr[i][j].z = p[2];
	if (p[0] < map->lx)
		map->lx = p[0];
	if (p[1] < map->ly)
		map->ly = p[1];
	if (p[0] > map->hx)
		map->hx = p[0];
	if (p[1] > map->hy)
		map->hy = p[1];
	return (p);
}

void ft_shift_img(t_map *map)
{
	int i;
	int j;
	int mid_x;
	int mid_y;
	int sh_x;
	int sh_y;

	mid_x = (ABS(map->lx) + ABS(map->hx)) / 2;
	mid_y = (ABS(map->ly) + ABS(map->hy)) / 2;
	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			if (map->lx < 0)
				map->coors_tr[i][j].x -= map->lx;
			map->coors_tr[i][j].x += (map->mid_scr[0] - mid_x);
			if (map->ly < 0)
				map->coors_tr[i][j].y -= map->ly;
			map->coors_tr[i][j].y += (map->mid_scr[1] - mid_y);
			j++;
		}
		i++;
	}
}

void ft_isometric_transformation(t_map *map)
{
	int i;
	int j;
	double p[3];

	// set lowest x and y coors to the first value
	ft_transform(map, p, 0, 0);
	map->lx = p[0];
	map->ly = p[1];

	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			ft_transform(map, p, i, j);
			j++;
		}
		i++;
	}
	ft_shift_img(map);
}



