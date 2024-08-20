/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:21:20 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 15:28:19 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_fdf_init_glib(t_glib *glib);
void		ft_fdf_init_map(t_map *map);
static void	ft_fdf_init_tmtrx(t_glib *glib);

/**
 * @brief Initialise graphic library attributes
 *
 * glib.proj - sets the projection type:
 * 	1 - isometric
 * 	2 - oblique
 * glib.x & glib.y = screen size
 *
 * @param glib Data struct
 */
void	ft_fdf_init_glib(t_glib *glib)
{
	ft_fdf_init_tmtrx(glib);
	glib->mlx = 0;
	glib->img = 0;
	glib->map = 0;
	glib->proj = 1;
	glib->oa = 0;
	glib->ob = 0;
	glib->x = 800;
	glib->y = 600;
}

/**
 * @brief Initialise map data.
 *
 * map.step_xy - initial point spread
 * map.dd.dx & map.dd.dy - should be half the screen
 * map.dd.dxy - midofyable point spread, init to 1
 * map.dd.dz - initial z stretch, init to 1
 * map.ax, map.ay, map.axy - initial rotation angles
 *
 * @param map Map struct
 */
void	ft_fdf_init_map(t_map *map)
{
	map->data_s = 0;
	map->coors = 0;
	map->coors_tr = 0;
	map->lz = 0;
	map->hz = 0;
	map->lc = 0xef8e38;
	map->hc = 0x108dc7;
	map->cc.dr = (map->lc >> 24) & 0xFF - (map->hc >> 24) & 0xFF;
	map->cc.dg = (map->lc >> 16) & 0xFF - (map->hc >> 16) & 0xFF;
	map->cc.db = (map->lc >> 8) & 0xFF - (map->hc >> 8) & 0xFF;
	map->cc.da = (map->lc) & 0xFF - (map->hc) & 0xFF;
	map->rl = 0;
	map->rc = 0;
	map->step_xy = 10;
	map->dd.dx = 400;
	map->dd.dy = 300;
	map->dd.dxy = 1;
	map->dd.dz = 1;
	map->ax = 0;
	map->ay = 0;
	map->axy = 0;
}

/**
 * @brief Initialise tR to isometric transformation
 *
 * @param glib Data struct
 */
static void	ft_fdf_init_tmtrx(t_glib *glib)
{
	glib->t_mtrx[0][0] = sqrt(2) / 2;
	glib->t_mtrx[0][1] = -sqrt(2) / 2;
	glib->t_mtrx[0][2] = 0;
	glib->t_mtrx[1][0] = sqrt(6) / 6;
	glib->t_mtrx[1][1] = sqrt(6) / 6;
	glib->t_mtrx[1][2] = -sqrt(6) / 3;
	glib->t_mtrx[2][0] = sqrt(3) / 3;
	glib->t_mtrx[2][1] = sqrt(3) / 3;
	glib->t_mtrx[2][2] = sqrt(3) / 3;
}
