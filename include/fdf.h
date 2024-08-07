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
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_point_d
{
	double	x;
	double	y;
	double	z;
}	t_point_d;

typedef struct s_map
{
	char		**data_s;
	t_point		**coors;
	t_point_d	**coors_tr;	// transformed coordinates
	int			mid_scr[2]; // coors of the middle of the screen
	int			rl; // row length
	int			rc; // row count
	int			step_xy; // number which sets the distance between points
	int			step_z; // number which sets the height of points
	double		lx; // lowest x coor
	double		ly; // lowest y coor
	double		hx; // highest x coor
	double		hy; // highest y coor
}	t_map;

typedef struct s_glib
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x_size;
	int			y_size;
	t_map		*map;
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

void keyboard_hook(mlx_key_data_t keydata, void *param);
void ft_bresenham(t_glib *glib, int start[2], int end[2]);
void ft_isometric_transformation(t_map *map);
void ft_put_points_3d(t_glib *glib, int p[3]);
void ft_put_points_2d(t_glib *glib, int p[2]);
void ft_draw_line(t_glib *glib, t_map *map);
void ft_parse_map(t_map *map, char *file);
void ft_draw_points(t_glib *glib, t_map *map);

#endif
