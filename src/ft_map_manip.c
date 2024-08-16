/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:08:40 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/16 20:23:06 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*

Map rendering:

prepare the poinits:
	-- move the centre to the origin
		-- original coors start at the origin		DONE (ft_map_parse)
	-- multiply by dxy								DONE (ft_map_render)
	-- modify by dz									DONE (ft_map_render)

calculate the projection:
	-- multiply each point by transformation matrix
		-- transformation matrix: projR * rot x * rot y * rot z
	-- NEED TO HAVE:
		* transformation matrix:
			-- glib.tR --> float[3][3]
				- init to isometric transformation;
				- change later ?


shift to the correct position:
	-- at beginning -> centre of the screen
		-- set init dx & dy offset to mid scr
	-- later -> based on dx & dy



Manipulations:

shifting x, y:
	-- change current coors by dx, dy
	-- record change in: map.dx, map.dy

zooming in, zooming out:
	-- change distance between coors by dxy
	-- keep centre coors unchanged
		-- shift to the origin
		-- stretch
		-- shift back
	-- record change in --> some struct
		-- NEED TO KNOW:
				* the centre i and j (rl/2, rc/2);
				* the offset of the centre from the origin (map.dx, map.dy)

change z (positive, negative):
	-- influences the projection calculation
		-- change original coors by dz
		-- perform isometric transformation
		-- shift and stretch the img by current x & y offset and dxy
	-- record change in --> some struct
		-- NEED TO KNOW:
			* relative position of the centre relative to the origin
			* current stretch factor

rotate around x, y, x=y:
	-- needs to be performed on the original coors
	-- NEED TO HAVE:
		* matrices: rotate around x, y and z by theta
		* functions: multiply point by mtrx, multiply mtrx by mtrx;
	-- NEED TO DO:
		* render map
*/


void ft_sh_x(t_glib *glib, t_point **c, float v)
{
	int i;
	int j;
	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			c[i][j].x += v;
			j++;
		}
		i++;
	}
}

void ft_sh_y(t_glib *glib, t_point **c, float v)
{
	int i;
	int j;
	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			c[i][j].y += v;
			j++;
		}
		i++;
	}
}

void ft_zoom_in(t_glib *glib, float v)
{
	t_map *map = glib->map;
	t_point **c = glib->map->coors_tr;
	int i;
	int j;
	double mid_x;
	double mid_y;
	double const_x;
	double const_y;

	mid_x = glib->x / 2 - map->coors_tr[map->rc / 2][map->rl / 2].x;
	mid_y = glib->y / 2 - map->coors_tr[map->rc / 2][map->rl / 2].y;
	const_x = (0.1 * glib->x / 2 + mid_x);
	const_y = (0.1 * glib->y / 2 + mid_y);
	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			c[i][j].x = (c[i][j].x + mid_x) * v - const_x;
			c[i][j].y = (c[i][j].y + mid_y) * v - const_y;
			j++;
		}
		i++;
	}
}
void ft_zoom_out(t_glib *glib, float v)
{
	t_map *map = glib->map;
	t_point **c = glib->map->coors_tr;
	int i;
	int j;
	double mid_x;
	double mid_y;
	double const_x;
	double const_y;

	mid_x = glib->x / 2 - map->coors_tr[map->rc / 2][map->rl / 2].x;
	mid_y = glib->y / 2 - map->coors_tr[map->rc / 2][map->rl / 2].y;
	const_x = mid_x - (glib->x / 2 - (glib->x / 2) * v);
	const_y = mid_y - (glib->y / 2 - (glib->y / 2) * v);
	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			c[i][j].x = (c[i][j].x + mid_x) * v - const_x;
			c[i][j].y = (c[i][j].y + mid_y) * v - const_y;
			j++;
		}
		i++;
	}
}

void ft_str_z(t_glib *glib, float v)
{
	// change z in coors
	// calculate projection
	t_map *map = glib->map;
	int i;
	int j;
	double mid_x;
	double mid_y;
	mid_x = glib->x / 2 - map->coors_tr[map->rc / 2][map->rl / 2].x;
	mid_y = glib->y / 2 - map->coors_tr[map->rc / 2][map->rl / 2].y;

	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			map->coors[i][j].z *= v;
			ft_pnt_by_mtrx(map->coors[i][j], &(map->coors_tr[i][j]), glib->isoR);
			printf("%.1f ", map->coors_tr[i][j].x);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_sh_x(glib, map->coors_tr, -mid_x);
	ft_sh_y(glib, map->coors_tr, -mid_y);
	// shift to original place
}

void ft_rotate_x(t_glib *glib, float v)
{
	int i;
	int j;
	t_map *map = glib->map;
	double mid_x;
	double mid_y;
	double mid_nx;
	double mid_ny;
	mid_x = glib->x / 2 - map->coors_tr[map->rc / 2][map->rl / 2].x;
	mid_y = glib->y / 2 - map->coors_tr[map->rc / 2][map->rl / 2].y;
	printf("00 mid x y: %.1f %.1f\n", mid_x, mid_y);

	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			// ft_pnt_by_mtrx(glib->map->coors_tr[i][j], &(glib->map->coors_tr[i][j]), glib->rxR);
			// printf("%.1f ", glib->map->coors_tr[i][j].x);
			j++;
		}
		// printf("\n");
		i++;
	}
	mid_nx = glib->x / 2 - map->coors_tr[map->rc / 2][map->rl / 2].x;
	mid_ny = glib->y / 2 - map->coors_tr[map->rc / 2][map->rl / 2].y;
	printf("01 mid x y: %.1f %.1f\n", mid_nx, mid_ny);
	// ft_point_shift(glib);
	ft_sh_x(glib, map->coors_tr, mid_nx);
	ft_sh_y(glib, map->coors_tr, mid_ny);
	printf("02 mid x y: %.1f %.1f\n", 400 - map->coors_tr[map->rc / 2][map->rl / 2].x, 300 - map->coors_tr[map->rc / 2][map->rl / 2].y);
}
