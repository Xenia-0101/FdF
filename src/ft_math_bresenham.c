/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:30:12 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 15:41:52 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_math_bresenham(t_glib *glib, t_point start, t_point end);
static void	ft_bresenham_v(t_glib *glib, t_line *line);
static void	ft_bresenham_h(t_glib *glib, t_line *line);
static void	ft_init_line(t_line *l, t_point p1, t_point p2);

/**
 * @brief Draws a line connecting two points.
 *
 * Based on dx and dy values, selects the algorithm to draw a line
 * between two points.
 * - dx and dy determine if the line is more vertical or more horisontal.
 *
 * @param glib	Data struct
 * @param start	Initial point
 * @param end	End point
 */
void	ft_math_bresenham(t_glib *glib, t_point start, t_point end)
{
	t_line	line;

	ft_init_line(&line, start, end);
	if (line.dx >= line.dy)
	{
		ft_bresenham_h(glib, &line);
	}
	else
	{
		ft_bresenham_v(glib, &line);
	}
}

/**
 * @brief Algorithm to draw a more horisontal line.
 *
 * * Uses Bresenham's algorithm to draw a line that is more horisontal
 * (passes through octants VIII, I, IV, V).
 *
 * @param glib Data struct
 * @param line Line struct
 */
static void	ft_bresenham_h(t_glib *glib, t_line *line)
{
	while (line->point[0] != line->end[0] + line->dx_sgn)
	{
		ft_put_point(glib, line->point);
		line->err += line->slope;
		if (line->err >= 0)
		{
			line->point[1] += line->dy_sgn;
			line->err += line->err_inc;
		}
		line->point[0] += line->dx_sgn;
	}
}

/**
 * @brief Algorithm to draw a more vertical line.
 *
 * Uses Bresenham's algorithm to draw a line that is more vertical
 * (passes through octants II, III, VI, VII).
 *
 * @param glib Data struct
 * @param line Line struct
 */
static void	ft_bresenham_v(t_glib *glib, t_line *line)
{
	while (line->point[1] != line->end[1] + line->dy_sgn)
	{
		ft_put_point(glib, line->point);
		line->err += line->slope;
		if (line->err >= 0)
		{
			line->point[0] += line->dx_sgn;
			line->err += line->err_inc;
		}
		line->point[1] += line->dy_sgn;
	}
}

/**
 * @brief Initialises Line struct values.
 *
 * Assigns values to initial, end and temp points of the line and calculates
 * constants required for Bresenham's line algorithm.
 *
 * @param l Line struct pointer
 * @param p1 Initial point
 * @param p2 End point
 */
static void	ft_init_line(t_line *l, t_point p1, t_point p2)
{
	l->start[0] = p1.x;
	l->start[1] = p1.y;
	l->end[0] = p2.x;
	l->end[1] = p2.y;
	l->point[0] = p1.x;
	l->point[1] = p1.y;
	l->dx = ft_abs(l->end[0] - l->start[0]);
	l->dy = ft_abs(l->end[1] - l->start[1]);
	l->dx_sgn = ft_sgn(l->end[0] - l->start[0]);
	l->dy_sgn = ft_sgn(l->end[1] - l->start[1]);
	if (l->dx >= l->dy)
	{
		l->slope = 2 * l->dy;
		l->err = -l->dx;
		l->err_inc = -2 * l->dx;
	}
	else
	{
		l->slope = 2 * l->dx;
		l->err = -l->dy;
		l->err_inc = -2 * l->dy;
	}
	l->dc = sqrt(l->dx * l->dx + l->dy * l->dy);
}
