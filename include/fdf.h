/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:16:19 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 12:04:14 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"

typedef struct s_change
{
	int		dx;
	int		dy;
	float	dz;
	float	dxy;
}	t_change;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_map
{
	t_point		**coors; // original coordinates
	t_point		**coors_tr;	// transformed coordinates
	char		**data_s;
	int			rl; // row length
	int			rc; // row count
	double		step_xy; // stretch horizontally
	t_change	dd;
	float		ax;		// rot angle around x axis, init to 0
	float		ay;		// rot angle around y axis, init to 0
	float		axy;		// rot angle around x=y axis, init to 0
}	t_map;

typedef struct s_glib
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	float		t_mtrx[3][3]; // isometric transformation
	int			x;
	int			y;
}	t_glib;

typedef struct s_line
{
	int		start[2];
	int		end[2];
	int		point[2];
	int		dx;
	int		dy;
	int		dx_sgn;
	int		dy_sgn;
	int		slope;
	int		err;
	int		err_inc;
}	t_line;

// ft_fdf_free.c
void	ft_fdf_free(t_glib *glib);
// ft_fdf_init.c
void	ft_fdf_init_glib(t_glib *glib);
void	ft_fdf_init_map(t_map *map);
// ft_fdf_utils.c
int		get_colour(int r, int g, int b, int a);
void	ft_put_point(t_glib *glib, int p[2]);
void	ft_reset_img(t_glib *glib);
int		ft_count_spaces(char *s);
//ft_map_draw.c
void	ft_map_draw(t_glib *glib);
// ft_map_manip.c
void	ft_sh_x(t_glib *glib, t_point **c, float v);
void	ft_sh_y(t_glib *glib, t_point **c, float v);
// ft_map_parse.c
int		ft_map_parse(t_glib *glib, char *filename);
// ft_map_recalc.c
void	ft_map_recalc(t_glib *glib, char o, float v);
// ft_map_transform.c
void	ft_map_transform(t_glib *glib);
// ft_math_bresenham.c
void	ft_math_bresenham(t_glib *glib, int start[2], int end[2]);
// ft_math_mtrx_calc.c
void	ft_pnt_by_mtrx(t_glib *glib, t_point p, t_point *q);
void	ft_mtrx_by_mtrx(float R1[3][3], float R2[3][3]);
// ft_math_set_mtrx.c
void	ft_set_iso_mtrx(float R[3][3]);
void	ft_set_rx_mtrx(float R[3][3], float t);
void	ft_set_ry_mtrx(float R[3][3], float t);
void	ft_set_rz_mtrx(float R[3][3], float t);
// ft_math_utils.c
float	ft_rad(int i);
int		ft_abs(int i);
int		ft_sgn(int i);
// keyboard_hook.c
void	keyboard_hook(mlx_key_data_t keydata, void *param);

#endif
