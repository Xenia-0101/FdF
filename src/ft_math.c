/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:32:56 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/17 16:05:30 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_init_R(float *R[3][3])
{
	int i;
	int j;
	int k;

	// Initialize all elements of result matrix R to 0
	while (i < 3) {
		j = 0;
		*R[i] = ft_calloc(3, sizeof (float));
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

	i = 0;
	// Initialize all elements of result matrix to 0
	while (i < 3) {
		j = 0;
		while (j < 3) {
			result[i][j] = 0.0;
			j++;
		}
		i++;
	}

	i = 0;
	// Multiply matrices R1 and R2, store result in temporary matrix result
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

	// Copy the result back into R1
	i = 0;
	while (i < 3) {
		j = 0;
		while (j < 3) {
			R1[i][j] = result[i][j];
			j++;
		}
		i++;
	}
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
	// rotate around z

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
	// rotate around x

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

void ft_set_tR(t_glib *glib, float *R[3][3])
{
	// rotate around x

	glib->tR[0][0] = *R[0][0];
	glib->tR[0][1] = *R[0][1];
	glib->tR[0][2] = *R[0][2];
	glib->tR[1][0] = *R[1][0];
	glib->tR[1][1] = *R[1][1];
	glib->tR[1][2] = *R[1][2];
	glib->tR[2][0] = *R[2][0];
	glib->tR[2][1] = *R[2][1];
	glib->tR[2][2] = *R[2][2];
}

