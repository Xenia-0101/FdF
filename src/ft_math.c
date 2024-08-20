/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:32:56 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/17 19:34:20 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_init_mtrx(float R[3][3])
{
	int i;
	int j;

	i = 0;
	while (i < 3) {
		j = 0;
		while (j < 3) {
			R[i][j] = 0.0;
			j++;
		}
		i++;
	}
}
static void ft_set_mtrx(float R1[3][3], float res[3][3])
{
	int i;
	int j;

	i = 0;
	while (i < 3) {
		j = 0;
		while (j < 3) {
			R1[i][j] = res[i][j];
			j++;
		}
		i++;
	}

}

void ft_pnt_by_mtrx(t_point p, t_point *q, t_change d, float R[3][3])
{
		q->x = R[0][0] * (p.x * d.dxy) + R[0][1] * (p.y * d.dxy) + R[0][2] * (p.z * d.dz);
		q->y = R[1][0] * (p.x * d.dxy) + R[1][1] * (p.y * d.dxy) + R[1][2] * (p.z * d.dz);
		q->z = R[2][0] * (p.x * d.dxy) + R[2][1] * (p.y * d.dxy) + R[2][2] * (p.z * d.dz);
}
void ft_mtrx_by_mtrx(float R1[3][3], float R2[3][3])
{
	float result[3][3];
	int i;
	int j;
	int k;

	ft_init_mtrx(result);
	i = 0;
	while (i < 3) {
		j = 0;
		while (j < 3) {
			k = 0;
			while (k < 3) {
				result[i][j] += R1[i][k] * R2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	ft_set_mtrx(R1, result);
}

void ft_set_isoR(float R[3][3])
{
	R[0][0] = sqrt(2) / 2;
	R[0][1] = -sqrt(2) / 2;
	R[0][2] = 0;
	R[1][0] = sqrt(6) / 6;
	R[1][1] = sqrt(6) / 6;
	R[1][2] = -sqrt(6) / 3;
	R[2][0] = sqrt(3) / 3;
	R[2][1] = sqrt(3) / 3;
	R[2][2] = sqrt(3) / 3;
}

void ft_set_rzR(float R[3][3], float v)
{
	float t = v * 3.14 / 180;

	R[0][0] = cos(t);
	R[0][1] = -sin(t);
	R[0][2] = 0.0;
	R[1][0] = sin(t);
	R[1][1] = cos(t);
	R[1][2] = 0.0;
	R[2][0] = 0.0;
	R[2][1] = 0.0;
	R[2][2] = 1.0;
}

void ft_set_ryR(float R[3][3], float v)
{
	float t = v * 3.14 / 180;
	// rotate around z

	R[0][0] = cos(t);
	R[0][1] = 0.0;
	R[0][2] = sin(t);
	R[1][0] = 0.0;
	R[1][1] = 1.0;
	R[1][2] = 0.0;
	R[2][0] = -sin(t);
	R[2][1] = 0.0;
	R[2][2] = cos(t);
}


void ft_set_rxR(float R[3][3], float v)
{
	float t = v * 3.14 / 180;

	R[0][0] = 1;
	R[0][1] = 0;
	R[0][2] = 0;
	R[1][0] = 0;
	R[1][1] = cos(t);
	R[1][2] = -sin(t);
	R[2][0] = 0;
	R[2][1] = sin(t);
	R[2][2] = cos(t);
}
