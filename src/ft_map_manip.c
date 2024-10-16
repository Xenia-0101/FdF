/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:08:40 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 11:43:42 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*

Map rendering:

prepare the poinits:
	-- move the centre to the origin
		-- original coors start at the origin		DONE (ft_map_parse)
	-- multiply by dxy								DONE (ft_map_render)
	-- modify by dz				DONE (ft_map_transform -> ft_pnt_by_mtrx)

// The following calculation has two options: firs is the initialization one,
// where coors_tr are calculated using isometric projection transformation.
// The other option is used for map transformation by the user.

calculate the projection:
	-- multiply each point by transformation matrix				DONE (ft_map_transform, ft_map_transform)
		-- transformation matrix: tR * rot x * rot y * rot z
	-- NEED TO HAVE:
		* transformation matrix									DONE (glib.tR --> float[3][3])
			- init to isometric projection;
		* rotation matrices										DONE (ft_math.c)


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

void	ft_sh_x(t_glib *glib, t_point **c, float v)
{
	int	i;
	int	j;

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

void	ft_sh_y(t_glib *glib, t_point **c, float v)
{
	int	i;
	int	j;

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
