/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_coors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:58:40 by xenia             #+#    #+#             */
/*   Updated: 2024/08/08 17:02:51 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_calculate_coors(t_map *map)
{
	int i = 0;
	int j;
	char **vals;

	while (i < map->rc)
	{
		vals = ft_split(map->data_s[i], ' ');
		j = 0;
		while (vals[j])
		{
			map->coors[i][j].x = j * map->step_xy;
			map->coors[i][j].y = i * map->step_xy;
			map->coors[i][j].z = ft_atoi(vals[j]) * map->step_z;
			j++;
		}
		free(vals);
		i++;
	}
}

