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

static void ft_set_matrix(t_glib *glib)
{
	float tempR[3][3];
	ft_set_isoR(glib->tR);
	if (glib->map->ax != 0)
	{
		ft_set_rxR(tempR, glib->map->ax);
		ft_mtrx_by_mtrx(glib->tR, tempR);
	}
	if (glib->map->ay != 0)
	{
		ft_set_ryR(tempR, glib->map->ay);
		ft_mtrx_by_mtrx(glib->tR, tempR);
	}
	if (glib->map->axy != 0)
	{
		ft_set_rzR(tempR, -45);
		ft_mtrx_by_mtrx(glib->tR, tempR);
		ft_set_rxR(tempR, glib->map->axy);
		ft_mtrx_by_mtrx(glib->tR, tempR);
		ft_set_rzR(tempR, 45);
		ft_mtrx_by_mtrx(glib->tR, tempR);
	}
}

int ft_map_transform(t_glib *glib)
{
	t_map *map;
	int i;
	int j;
	float mid_x;
	float mid_y;

	ft_set_matrix(glib);
	map = glib->map;
	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			ft_pnt_by_mtrx(map->coors[i][j], &(map->coors_tr[i][j]), map->dd, glib->tR);
			j++;
		}
		i++;
	}
	mid_x = map->coors_tr[map->rc/2][map->rl/2].x;
	mid_y = map->coors_tr[map->rc/2][map->rl/2].y;
	ft_sh_x(glib, map->coors_tr, map->dd.dx - mid_x);
	ft_sh_y(glib, map->coors_tr, map->dd.dy - mid_y);
	return (1);
}

