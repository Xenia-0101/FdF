
// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "fdf.h"
// #define SGN(_x) ((_x) >= 0 || -1)


// static void ft_hook(void *param)
// {
// 	const mlx_t *mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);	//	TODO: remove printf
// }


int32_t main(void)
{
	int sa = 500;
	int sb = 200;

	int A[3] = {sa, sb, 50};
	int B[3] = {sa+50, sb, 50};
	int C[3] = {sa, sb+50, 50};
	int D[3] = {sa+50, sb+50, 50};
	int E[3] = {sa, sb, 150};
	int F[3] = {sa+50, sb, 150};
	int G[3] = {sa, sb+50, 150};
	int H[3] = {sa+50, sb+50, 150};

	t_map map;
	mlx_t *mlx = mlx_init(800, 600, "MLX42 Library", true);
	if (!mlx)
		printf("Library not created\n");	//	TODO: remove printf

	// create and display the image
	mlx_image_t *img = mlx_new_image(mlx, 800, 600);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		printf("Image not created\n");	//	TODO: remove printf

	map.mlx = mlx;
	map.img = img;
	// set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof (int32_t));

	ft_put_points(&map, A);
	ft_put_points(&map, B);
	ft_put_points(&map, C);
	ft_put_points(&map, D);
	// ft_put_points(&map, sa, sb+50, 150);
	// ft_put_points(&map, sa+50, sb+50, 150);
	// ft_put_points(&map, sa, sb, 150);
	// ft_put_points(&map, sa+50, sb, 150);

	// Bresenham's algorithm
	ft_bresenham(&map, A, B);
	ft_bresenham(&map, B, D);
	// ft_bresenham(&map, D, C);
	// ft_bresenham(&map, C, A);
	// ft_bresenham(&map, E, F);
	// ft_bresenham(&map, F, H);
	// ft_bresenham(&map, H, G);
	// ft_bresenham(&map, G, E);
	// ft_bresenham(&map, A, E);
	// ft_bresenham(&map, B, F);
	// ft_bresenham(&map, D, H);
	// ft_bresenham(&map, C, G);



	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(map.mlx, &keyboard_hook, &map);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
