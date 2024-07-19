
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


int32_t main(void)
{
	int win_size = 256;
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t *mlx = mlx_init(win_size, win_size, "MLX42 Library", true);
	if (!mlx)
		printf("Library not created\n");	//	TODO: remove printf

	// create and display the image
	mlx_image_t *img = mlx_new_image(mlx, 236, 236);
	if (!img || (mlx_image_to_window(mlx, img, 10, 10) < 0))
		printf("Image not created\n");	//	TODO: remove printf

	// set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof (int32_t));

	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(mlx, &keyboard_hook, "1");
	mlx_loop(mlx);
	
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
