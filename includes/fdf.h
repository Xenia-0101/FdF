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


typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	*img;
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
void ft_bresenham(t_map *map, int start[2], int end[2]);
void ft_bresenham1(t_map *map, int start[3], int end[3]);
void ft_put_points_3d(t_map *map, int p[3]);
void ft_put_points_2d(t_map *map, int p[2]);

#endif
