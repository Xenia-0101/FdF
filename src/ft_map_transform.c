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

void		ft_map_transform(t_glib *glib);
static void	ft_set_matrix(t_glib *glib);

/**
 * @brief Sets the tR to represent projection and rotation.
 *
 * Based on recorded angles (map.ax, map.ay, map.az), multiplies the tR
 * (transformation matrix) by matrix corresponding to the required rotation.
 * Example:
 * - if map.ax = 30, the img should be rotated by 30˚ around the x-axis.
 * - temporary matrix is set to represent desired rotation by calling
 *   the ft_set_rxR function and tR is multiplied by temp_r. The result is then
 *   stored in tR.
 * The rotation around x = y line is realised by rotation around z-axis by -45˚
 * (to make a = y line corresponding to the x-axis) and subsequent rotation
 * around x-axis.
 *
 * @param glib Data struct
 */
static void	ft_set_matrix(t_glib *glib)
{
	float	temp_r[3][3];

	ft_set_isoR(glib->tR);
	if (glib->map->ax != 0)
	{
		ft_set_rxR(temp_r, glib->map->ax);
		ft_mtrx_by_mtrx(glib->tR, temp_r);
	}
	if (glib->map->ay != 0)
	{
		ft_set_ryR(temp_r, glib->map->ay);
		ft_mtrx_by_mtrx(glib->tR, temp_r);
	}
	if (glib->map->axy != 0)
	{
		ft_set_rzR(temp_r, -45);
		ft_mtrx_by_mtrx(glib->tR, temp_r);
		ft_set_rxR(temp_r, glib->map->axy);
		ft_mtrx_by_mtrx(glib->tR, temp_r);
		ft_set_rzR(temp_r, 45);
		ft_mtrx_by_mtrx(glib->tR, temp_r);
	}
}

/**
 * @brief Transforms map.coors to represent modified img.
 *
 * Iterates through each point in map.coors and multiplies it
 * by tR (transformation matrix).
 * @snippet
 * mid_x & mid_y - coordinates of the middle point
		mid_x = map->coors_tr[map->rc/2][map->rl/2].x;
		mid_y = map->coors_tr[map->rc/2][map->rl/2].y;
 * shift the middle point of the imgto the screen centre changed by dx & dy
		ft_sh_x(glib, map->coors_tr, map->dd.dx - mid_x);
		ft_sh_y(glib, map->coors_tr, map->dd.dy - mid_y);

 * @param glib Data struct
 */
void	ft_map_transform(t_glib *glib)
{
	t_map	*map;
	int		i;
	int		j;
	float	mid_x;
	float	mid_y;

	ft_set_matrix(glib);
	map = glib->map;
	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			ft_pnt_by_mtrx(map->coors[i][j], &(map->coors_tr[i][j]), glib);
			j++;
		}
		i++;
	}
	mid_x = map->coors_tr[map->rc / 2][map->rl / 2].x;
	mid_y = map->coors_tr[map->rc / 2][map->rl / 2].y;
	ft_sh_x(glib, map->coors_tr, map->dd.dx - mid_x);
	ft_sh_y(glib, map->coors_tr, map->dd.dy - mid_y);
}
