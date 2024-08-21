/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_mtrx_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:02:33 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/21 11:34:15 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_mtrx(float R[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			R[i][j] = 0.0;
			j++;
		}
		i++;
	}
}

static void	ft_set_mtrx(float R1[3][3], float res[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			R1[i][j] = res[i][j];
			j++;
		}
		i++;
	}
}

void	ft_pnt_by_mtrx(t_glib *glib, t_point p, t_point *q)
{
	t_change	d;
	float		nx;
	float		ny;
	float		nz;

	d = glib->map->dd;
	nx = p.x * d.dxy;
	ny = p.y * d.dxy;
	nz = p.z * d.dz;
	q->x = glib->t_mtrx[0][0] * nx + glib->t_mtrx[0][1] * ny;
	q->x += glib->t_mtrx[0][2] * nz;
	q->y = glib->t_mtrx[1][0] * nx + glib->t_mtrx[1][1] * ny;
	q->y += glib->t_mtrx[1][2] * nz;
	q->z = glib->t_mtrx[2][0] * nx + glib->t_mtrx[2][1] * ny;
	q->z += glib->t_mtrx[2][2] * nz;
}

void	ft_mtrx_by_mtrx(float R1[3][3], float R2[3][3])
{
	float	result[3][3];
	int		i;
	int		j;
	int		k;

	ft_init_mtrx(result);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			while (k < 3)
			{
				result[i][j] += R1[i][k] * R2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	ft_set_mtrx(R1, result);
}
