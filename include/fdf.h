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


typedef struct s_glib
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_glib;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	char	**data_s;
	int		**data_i;
	t_point	**coors;
	int		rl; // row length
	int		rc; // row count
}	t_map;

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
void ft_put_points_3d(t_glib *glib, int p[3]);
void ft_put_points_2d(t_glib *glib, int p[2]);
void ft_draw_line(t_glib *glib, t_map *map);

#endif
