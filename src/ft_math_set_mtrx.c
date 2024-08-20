/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_set_mtrx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:57:43 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 13:30:06 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_obl_mtrx(t_glib *glib, float R[3][3]);
void	ft_set_iso_mtrx(float R[3][3]);
void	ft_set_rx_mtrx(float R[3][3], float v);
void	ft_set_ry_mtrx(float R[3][3], float v);
void	ft_set_rz_mtrx(float R[3][3], float v);

void	ft_set_obl_mtrx(t_glib *glib, float R[3][3])
{
	float	t;

	t = ft_rad(glib->ob);
	R[0][0] = 1;
	R[0][1] = 0;
	R[0][2] = glib->oa * cos(t);
	R[1][0] = 0;
	R[1][1] = 1;
	R[1][2] = glib->oa * sin(t);
	R[2][0] = 0;
	R[2][1] = 0;
	R[2][2] = 1;
}

void	ft_set_iso_mtrx(float R[3][3])
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

void	ft_set_rz_mtrx(float R[3][3], float v)
{
	float	t;

	t = ft_rad(v);
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

void	ft_set_ry_mtrx(float R[3][3], float v)
{
	float	t;

	t = ft_rad(v);
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

void	ft_set_rx_mtrx(float R[3][3], float v)
{
	float	t;

	t = ft_rad(v);
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
