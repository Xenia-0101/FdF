/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_transform.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:58:29 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/14 20:03:24 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_map_transform(t_glib *glib)
{
	printf("Map transform...\n");
	t_map *map;
	int i;
	int j;
	float mid_x;
	float mid_y;

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
			ft_pnt_by_mtrx(map->coors[i][j], &(map->coors_tr[i][j]), glib->tR, 1);
			map->coors_tr[i][j].z = map->coors[i][j].z;		// keep z the same for z manipulation and repeated calculation
			j++;
		}
		i++;
	}
	mid_x = map->coors_tr[map->rc/2][map->rl/2].x;
	mid_y = map->coors_tr[map->rc/2][map->rl/2].y;
	ft_sh_x(glib, map->coors_tr, map->dx - mid_x);
	ft_sh_y(glib, map->coors_tr, map->dy - mid_y);
	return (1);
}

int ft_map_transform_2(t_glib *glib)
{
	printf("Map transform 2...\n");
	t_map *map;
	int i;
	int j;
	float mid_x;
	float mid_y;
	float rotX[3][3];
	float rotY[3][3];
	float rotZ[3][3];

	ft_set_isoR(glib->tR);
	if (glib->map->ax != 0)
	{
		ft_set_rxR(rotX, glib->map->ax);
		ft_mtrx_by_mtrx(glib->tR, rotX);
	}
	if (glib->map->ay != 0)
	{
		ft_set_ryR(rotY, glib->map->ay);
		ft_mtrx_by_mtrx(glib->tR, rotY);
	}
	if (glib->map->axy != 0)
	{
		ft_set_rzR(rotZ, -45);
		ft_mtrx_by_mtrx(glib->tR, rotZ);
		ft_set_rxR(rotX, glib->map->axy);
		ft_mtrx_by_mtrx(glib->tR, rotX);
		ft_set_rzR(rotZ, 45);
		ft_mtrx_by_mtrx(glib->tR, rotZ);
	}
	if (glib->map->dz != 10)
	{

	}

	map = glib->map;
	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			ft_pnt_by_mtrx(map->coors[i][j], &(map->coors_tr[i][j]), glib->tR, map->dz);
			j++;
		}
		i++;
	}
	mid_x = map->coors_tr[map->rc/2][map->rl/2].x;
	mid_y = map->coors_tr[map->rc/2][map->rl/2].y;
	ft_sh_x(glib, map->coors_tr, map->dx - mid_x);
	ft_sh_y(glib, map->coors_tr, map->dy - mid_y);
	printf("first point x y: %.1f %.1f\n", map->coors_tr[0][0].x, map->coors_tr[0][0].y);
	printf("mid point x y: %.1f %.1f\n", map->coors_tr[map->rc/2][map->rl/2].x, map->coors_tr[map->rc/2][map->rl/2].y);
	printf("last point x y: %.1f %.1f\n", map->coors_tr[(map->rc)-1][(map->rl)-1].x, map->coors_tr[(map->rc)-1][(map->rl)-1].y);
	printf("\n");
	return (1);
}

