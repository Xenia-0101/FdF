/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:30:12 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/02 19:42:55 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ABS(_x) ((_x) >= 0 ? (_x) : -(_x))
#define SGN(_x) ((_x) < 0 ? -1 : \
						 ((_x) > 0 ? 1 : 0))

static void ft_init_line(t_line *l, int p1[2], int p2[2])
{
	l->start[0] = p1[0];
	l->start[1] = p1[1];
	l->end[0] = p2[0];
	l->end[1] = p2[1];
	l->point[0] = l->start[0];
	l->point[1] = l->start[1];
	l->dx = l->end[0] - l->start[0];
	l->dy = l->end[1] - l->start[0];
	l->xInc = SGN(l->dx);
	l->yInc = SGN(l->dy);
	l->slope = 2 * l->dy;
	l->err = -l->dx;
	l->errInc = -2 * l->dx;
}

void ft_bresenham(t_map *map, int start[2], int end[2])
{
	t_line line;

	ft_init_line(&line, start, end);

	printf("dy: %d\n", line.dy);

	if (line.dy == 0)
	{
		printf("HORIZONTAL LINE\n");
		printf("point[0]: %d end[0]: %d xInc: %d\n", line.point[0], line.end[0], line.xInc);
		while (line.point[0] != line.end[0] + line.xInc)
		{
			printf("%d %d\n", line.point[0], line.point[1]);
			ft_put_points_2d(map, line.point);
			line.point[0] += line.xInc;
		}
	}

}
