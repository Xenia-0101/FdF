
// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

#include "fdf.h"

// static void ft_hook(void *param)
// {
// 	const mlx_t *mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);	//	TODO: remove printf
// }

void ft_put_points(t_map *map, int x, int y, int z)
{
	double px = x * cos(120) + y * cos(122) + z * cos(118);
	double py = x * sin(120) + y * sin(122) + z * sin(118);
	// mlx_put_pixel(map->img, px, py, 0);
	printf("\t%f %f\n", px, py);
}

int32_t main(void)
{
	t_map *map;
	mlx_t *mlx = mlx_init(800, 600, "MLX42 Library", true);
	if (!mlx)
		printf("Library not created\n");	//	TODO: remove printf

	// create and display the image
	mlx_image_t *img = mlx_new_image(mlx, 800, 600);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		printf("Image not created\n");	//	TODO: remove printf

	map->mlx = mlx;
	map->img = img;
	// set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof (int32_t));

	ft_put_points(map, 50, 50, 50);
	ft_put_points(map, 200, 50, 50);
	ft_put_points(map, 50, 200, 50);
	ft_put_points(map, 200, 200, 50);
	ft_put_points(map, 50, 50, 200);
	ft_put_points(map, 200, 50, 200);
	ft_put_points(map, 50, 200, 200);
	ft_put_points(map, 200, 200, 200);



	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(map->mlx, &keyboard_hook, map);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
