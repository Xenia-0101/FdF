/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:32:56 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/16 20:03:21 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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