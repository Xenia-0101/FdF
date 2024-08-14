/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric_transformation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:58:29 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/14 20:03:24 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_point_shift(t_glib *glib)
{
	printf("Shifting points transformation...\n");
	t_map *map;
	int i;
	int j;
	double mid_x;
	double mid_y;

	map = glib->map;
	mid_x = map->coors_tr[map->rc / 2][map->rl / 2].x * map->step_xy;
	mid_y = map->coors_tr[map->rc / 2][map->rl / 2].y * map->step_xy;

	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			map->coors_tr[i][j].x = map->coors_tr[i][j].x * map->step_xy + (glib->x / 2 - mid_x);
			map->coors_tr[i][j].y = map->coors_tr[i][j].y * map->step_xy + (glib->y / 2 - mid_y);
			printf("%4.1f ", map->coors_tr[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}

}

int ft_isometric_transformation(t_glib *glib)
{
	printf("Isometric transformation...\n");
	t_map *map;
	int i;
	int j;

	map = glib->map;
	i = 0;
	if (!(map->coors_tr = (t_point **)ft_calloc(map->rc, sizeof (t_point *))))
		return (-1);
	while (i < map->rc)
	{
		if (!(map->coors_tr[i] = (t_point *)ft_calloc(map->rl, sizeof (t_point))))
			return (-1);
		j = 0;
		while (j < map->rl)
		{
			ft_point_matrix(map->coors[i][j], &(map->coors_tr[i][j]), glib->isoR);
			map->coors_tr[i][j].z = map->coors[i][j].z;		// keep z the same for z manipulation and repeated calculation
			printf("%4.1f ", map->coors_tr[i][j].x);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	ft_point_shift(glib);
	return (1);
}

