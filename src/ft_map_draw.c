/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:49:05 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 14:08:31 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_map_draw(t_glib *glib);
static void	ft_draw_v(t_glib *glib, t_map *map);
static void	ft_draw_h(t_glib *glib, t_map *map);

/**
 * @brief Calls functions that take care of drawing.
 *
 * @param glib	Data struct
 */
void	ft_map_draw(t_glib *glib)
{
	ft_draw_v(glib, glib->map);
	ft_draw_h(glib, glib->map);
}

/**
 * @brief Calls function to draw horisontal lines.
 *
 * Iterates through the map coordinates and calls
 * ft_math_bresenham function with starting point (current)
 * and ending point (next column).
 *
 * @param glib	Data struct
 * @param map	Map struct
 */
static void	ft_draw_h(t_glib *glib, t_map *map)
{
	int	p1[2];
	int	p2[2];
	int	i;
	int	j;

	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl - 1)
		{
			p1[0] = map->coors_tr[i][j].x;
			p1[1] = map->coors_tr[i][j].y;
			p2[0] = map->coors_tr[i][j + 1].x;
			p2[1] = map->coors_tr[i][j + 1].y;
			ft_math_bresenham(glib, map->coors_tr[i][j], map->coors_tr[i][j + 1]);
			j++;
		}
		i++;
	}
}
/* static void	ft_draw_h(t_glib *glib, t_map *map)
{
	int	p1[2];
	int	p2[2];
	int	i;
	int	j;

	i = 0;
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl - 1)
		{
			p1[0] = map->coors_tr[i][j].x;
			p1[1] = map->coors_tr[i][j].y;
			p2[0] = map->coors_tr[i][j + 1].x;
			p2[1] = map->coors_tr[i][j + 1].y;
			ft_math_bresenham(glib, p1, p2);
			j++;
		}
		i++;
	}
} */

/**
 * @brief Calls function to draw vertical lines.
 *
 * Iterates through the map coordinates and calls
 * ft_math_bresenham function with starting point (current)
 * and ending point (one row below).
 *
 * @param glib	Data struct
 * @param map	Map struct
 */
static void	ft_draw_v(t_glib *glib, t_map *map)
{
	int	p1[3];
	int	p2[3];
	int	i;
	int	j;

	i = 0;
	while (i < map->rc - 1)
	{
		j = 0;
		while (j < map->rl)
		{
			p1[0] = map->coors_tr[i][j].x;
			p1[1] = map->coors_tr[i][j].y;
			p2[0] = map->coors_tr[i + 1][j].x;
			p2[1] = map->coors_tr[i + 1][j].y;
			ft_math_bresenham(glib, map->coors_tr[i][j], map->coors_tr[i + 1][j]);
			j++;
		}
		i++;
	}
}
/* static void	ft_draw_v(t_glib *glib, t_map *map)
{
	int	p1[3];
	int	p2[3];
	int	i;
	int	j;

	i = 0;
	while (i < map->rc - 1)
	{
		j = 0;
		while (j < map->rl)
		{
			p1[0] = map->coors_tr[i][j].x;
			p1[1] = map->coors_tr[i][j].y;
			p2[0] = map->coors_tr[i + 1][j].x;
			p2[1] = map->coors_tr[i + 1][j].y;
			ft_math_bresenham(glib, p1, p2);
			j++;
		}
		i++;
	}
} */
