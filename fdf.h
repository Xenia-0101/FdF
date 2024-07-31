#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>

# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_map;


void keyboard_hook(mlx_key_data_t keydata, void *param);


#endif
