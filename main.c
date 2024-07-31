
// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "fdf.h"

// static void ft_hook(void *param)
// {
// 	const mlx_t *mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);	//	TODO: remove printf
// }

void ft_put_points(t_map *map, int p[3])
{
	double px = p[0] * cos(120) + p[1] * cos(122) + p[2] * cos(118);
	double py = p[0] * sin(120) + p[1] * sin(122) + p[2] * sin(118);
	if (px > 0 && py > 0)
		mlx_put_pixel(map->img, px, py, 0);
	printf("\t%f %f\n", px, py);
}

void ft_bresenham(t_map *map, int start[3], int end[3])
{
	int dx;
	int dy;
	int xx;
	int yy;
	int pp;

	xx = start[0];
	yy = start[1];
	dx = end[0] - xx;
	dy = end[1] - yy;
	pp = 2 * dy - dx;

	printf("xx\tyy\n");
	printf("%d\t%d\n", xx, yy);
	while (start[0] < end[0])
	{
		printf("%d\t%d\n", start[0], start[1]);
		if (pp < 0)
		{
			pp += 2 * dy;
		}
		else
		{
			pp += 2 * dy;
			start[1] += 1;
		}
		ft_put_points(map, start);
		start[0] += 1;
	}
}

void ft_simple_line(t_map *map, int start[3], int end[3])
{
	double slope = (end[1] - start[1])/(end[0] - start[0]);
	int sy = start[1];
	while (start[0] < end[0])
	{
		ft_put_points(map, start);
		start[0] += 1;
		start[1] = slope * start[0] + sy;
	}
}

int32_t main(void)
{
	int sa = 500;
	int sb = 200;

	int A[3] = {sa, sb, 50};
	int B[3] = {sa+50, sb, 50};
	int C[3] = {sa, sb+50, 50};
	int D[3] = {sa+50, sb+50, 50};

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
	// ft_bresenham(&map, C, D);
	// ft_bresenham(&map, A, C);
	// ft_bresenham(&map, B, D);

	ft_simple_line(&map, C, D);


	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(map.mlx, &keyboard_hook, &map);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
