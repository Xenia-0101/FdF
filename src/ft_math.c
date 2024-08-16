/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:32:56 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/16 20:59:24 by xvislock         ###   ########.fr       */
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
void ft_pnt_by_mtrx(t_point p, t_point *q, float R[3][3])
{
		q->x = R[0][0] * p.x + R[0][1] * p.y + R[0][2] * p.z;
		q->y = R[1][0] * p.x + R[1][1] * p.y + R[1][2] * p.z;
		q->z = R[2][0] * p.x + R[2][1] * p.y + R[2][2] * p.z;
}

void ft_mtrx_by_mtrx(float R1[3][3], float R2[3][3], float *R[3][3])
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 3) {
		j = 0;
		while (j < 3) {
			k = 0;
			while (k < 3) {
				*R[i][j] += R1[i][k] * R2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

void ft_set_isoR(float *R[3][3])
{
	*R[0][0] = sqrt(2) / 2;
	*R[0][1] = -sqrt(2) / 2;
	*R[0][2] = 0;

	*R[1][0] = sqrt(6) / 6;
	*R[1][1] = sqrt(6) / 6;
	*R[1][2] = -sqrt(6) / 3;

	*R[2][0] = sqrt(3) / 3;
	*R[2][1] = sqrt(3) / 3;
	*R[2][2] = sqrt(3) / 3;
}

void ft_set_rzR(float *R[3][3], float t)
{
	// rotate around z

	*R[0][0] = cos(t);
	*R[0][1] = -sin(t);
	*R[0][2] = 0.0;

	*R[1][0] = sin(t);
	*R[1][1] = cos(t);
	*R[1][2] = 0.0;

	*R[2][0] = 0.0;
	*R[2][1] = 0.0;
	*R[2][2] = 1.0;
}

void ft_set_rxR(float *R[3][3], float t)
{
	// rotate around x
	ft_init_R(R);

	*R[0][0] = 1;
	*R[0][1] = 0;
	printf("iniit R\n");
	*R[0][2] = 0;

	*R[1][0] = 0;
	*R[1][1] = cos(1);
	*R[1][2] = -sin(1);

	*R[2][0] = 0;
	*R[2][1] = sin(1);
	*R[2][2] = cos(1);
}
