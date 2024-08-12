/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric_transformation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:58:29 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/12 18:29:21 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Allocates memory for map->coors
// Requires map->rl and map->rc values to be set correctly

static void ft_coors_allocate(t_map *map)
{
	int i;

	map->coors = (t_point_d **)ft_calloc(map->rc + 1, sizeof (t_point_d *));
	if (map->coors == NULL)			// TODO: Error handling
	{
		return ;		// ToDo: Exit safely
	}
	i = 0;
	while (i < map->rc)
	{
		map->coors[i] = (t_point_d *)ft_calloc(map->rl + 1, sizeof (t_point_d));
		i++;
	}
}
static double *ft_transform(t_map *map, double p[2], int i, int j)
{
	double z;

	z = map->data_i[i][j] * map->step_z;
	p[0] = j * cos(120) + i * cos(122) + z * cos(118);
	p[1] = j * sin(120) + i * sin(122) + z * sin(118);
	map->coors[i][j].x = p[0];
	map->coors[i][j].y = p[1];
	return (p);
}

void ft_isometric_transformation(t_map *map)
{
	int i;
	int j;
	double p[2];

	// set lowest x and y coors to the first value
	ft_coors_allocate(map);
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
			// printf("%5.1f ", map->coors[i][j].x);
			j++;
		}
		// printf("\n");
		i++;
	}
	// printf("|| %5.1f %5.1f ||\n", map->coors[0][18].x, map->coors[0][18].y);
}
