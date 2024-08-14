/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:30:12 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/14 17:55:01 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_init_line(t_line *l, int p1[2], int p2[2])
{
	l->start[0] = p1[0];
	l->start[1] = p1[1];
	l->end[0] = p2[0];
	l->end[1] = p2[1];
	l->point[0] = p1[0];
	l->point[1] = p1[1];
	l->dx = ABS(l->end[0] - l->start[0]);
	l->dy = ABS(l->end[1] - l->start[1]);
	l->dx_sgn = SGN(l->end[0] - l->start[0]);
	l->dy_sgn = SGN(l->end[1] - l->start[1]);
	if (l->dx >= l->dy)
	{
		l->slope = 2 * l->dy;
		l->err = -l->dx;
		l->errInc = -2 * l->dx;
	}
	else
	{
		l->slope = 2 * l->dx;
		l->err = -l->dy;
		l->errInc = -2 * l->dy;
	}
}

static void ft_bresenham_h(t_glib *glib, t_line *line)
{
	while (line->point[0] != line->end[0] + line->dx_sgn)
	{
		ft_put_point(glib, line->point);
		line->err += line->slope;
		if (line->err >= 0)
		{
			line->point[1] += line->dy_sgn;
			line->err += line->errInc;
		}
		line->point[0] += line->dx_sgn;
	}

}

static void ft_bresenham_v(t_glib *glib, t_line *line)
{
	while (line->point[1] != line->end[1] + line->dy_sgn)
	{
		ft_put_point(glib, line->point);
		line->err += line->slope;
		if (line->err >= 0)
		{
			line->point[0] += line->dx_sgn;
			line->err += line->errInc;
		}
		line->point[1] += line->dy_sgn;
	}
}

void ft_bresenham(t_glib *glib, int start[2], int end[2])
{
	t_line line;
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
