/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:30:12 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/01 19:56:54 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* void ft_bresenham(t_map *map, int start[3], int end[3])
{
	int dx;
	int dy;
	int slope;
	int err;
	int errInc;
	int point[3];

	dx = end[0] - start[0];
	dy = end[1] - start[1];
	slope = 2 * dy;
	err = -dx;
	errInc = -2 * dx;
	point[0] = start[0];
	point[1] = start[1];
	point[2] = start[2];

	printf("xx\tyy\n");
	while (point[0] <= end[0])
	{
		ft_put_points(map, point);
		printf("%d\t%d\n", point[0], point[1]);
		err += slope;
		if (err >= 0)
		{
			point[1]++;
			err += errInc;
		}
		point[0]++;
	}
}
*/

static void ft_b_vertical(t_map *map, t_line *line)
{
	while (line->point[1] != line->end[1] + line->yInc)
	{
		ft_put_points(map, line->point);
		line->point[1] += line->yInc;
	}
}

static void ft_b_horizontal(t_map *map, t_line *line)
{
	while (line->point[0] != line->end[0] + line->xInc)
	{
		ft_put_points(map, line->point);
		line->point[0] += line->xInc;
	}
}

static void ft_b_more_vertical(t_map *map, t_line *line)
{
	while (line->point[1] != line->end[1] + line->yInc)
	{
		ft_put_points(map, line->point);
		line->err += line->slope;
		if (line->err >= 0)
		{
			line->point[0] += line->xInc;
			line->err += line->errInc;
		}
		line->point[1] += line->yInc;
	}
}

static void ft_b_more_horizontal(t_map *map, t_line *line)
{
	while (line->point[0] != line->end[0] + line->xInc)
	{
		line->err += line->slope;
		if (line->err >= 0)
		{
			line->point[1] += line->yInc;
			line->err += line->errInc;
		}
		line->point[0] += line->xInc;
	}

}

void ft_bresenham(t_map *map, int start[2], int end[2])
{
	t_line line;

	line.end[0] = end[0];
	line.end[1] = end[1];
	line.start[0] = start[0];
	line.start[1] = start[1];
	line.point[0] = start[0];
	line.point[1] = start[1];
	line.dx = line.end[0] - line.start[0];
	line.dy = line.end[1] - line.start[1];
	line.xInc = SGN(line.dx);
	line.yInc = SGN(line.dy);
	line.slope = 2 * line.dy;
	line.err = -abs(line.dx);
	line.errInc = -2 * abs(line.dx);


	if (line.dy == 0)
	{
		ft_b_horizontal(map, &line);
	}
	else if (line.dx == 0)
	{
		ft_b_vertical(map, &line);
	}
	// else if (line.dx < line.dy)
	// {
	// 	ft_b_more_vertical(map, &line);
	// }
	// else
	// {
	// 	ft_b_more_horizontal(map, &line);
	// }
}
