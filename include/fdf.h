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

#define ABS(_x) ((_x) >= 0 ? (_x) : -(_x))
#define SGN(_x) ((_x) < 0 ? -1 : \
						 ((_x) > 0 ? 1 : 0))


typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_map
{
	char		**data_s;
	int			**data_i;
	t_point		**coors; // original coordinates

	t_point		**coors_tr;	// transformed coordinates

	int			rl; // row length
	int			rc; // row count
	double		step_z; // stretch vertically
	double		step_xy; // stretch horizontally

	int			sh_x;
}	t_map;

typedef struct s_glib
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	float		isoR[3][3]; // isometric transformation
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
	int		errInc;
}	t_line;

void ft_bresenham(t_glib *glib, int start[2], int end[2]);
void ft_draw(t_glib *glib, t_map *map);
void ft_manipulate_img(t_glib *glib, char o, float v);
void keyboard_hook(mlx_key_data_t keydata, void *param);
int ft_isometric_transformation(t_glib *glib);
void ft_point_shift(t_glib *glib);
int ft_map_parse(t_glib *glib, char *filename);
// utils
// int get_colour(int r, int g, int b);
int get_colour(int r, int g, int b, int a);
void ft_put_point(t_glib *glib, int p[2]);
void ft_reset_img(t_glib *glib);
// math
void ft_point_matrix(t_point p, t_point *q, float R[3][3]);

#endif
