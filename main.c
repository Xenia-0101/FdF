
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

int *ft_transform_2d(int p3[3], int p2[2])
{
	p2[0] = p3[0] * cos(120) + p3[1] * cos(122) + p3[2] * cos(118);
	p2[1] = p3[0] * sin(120) + p3[1] * sin(122) + p3[2] * sin(118);
	return (p2);
}

int32_t main(void)
{
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

	// DEFINE 8 POINTS IN 3D

	int A[3] = {500, 200, 0};
	int B[3] = {550, 200, 0};
	int C[3] = {550, 250, 0};
	int D[3] = {500, 250, 0};
	int E[3] = {500, 200, 70};
	int F[3] = {550, 200, 70};
	int G[3] = {550, 250, 70};
	int H[3] = {500, 250, 70};

	// TRANSFORM THE POINTS TO 2D

	int AA[2];
	int BB[2];
	int CC[2];
	int DD[2];
	int EE[2];
	int FF[2];
	int GG[2];
	int HH[2];
	int test[2] = {235, 395};

	// ft_transform_2d(A, AA);
	// ft_transform_2d(B, BB);
	// ft_transform_2d(C, CC);
	// ft_transform_2d(D, DD);
	// ft_transform_2d(E, EE);
	// ft_transform_2d(F, FF);
	// ft_transform_2d(G, GG);
	// ft_transform_2d(H, HH);
	// printf("A: %d %d\n", AA[0], AA[1]);
	// printf("B: %d %d\n", BB[0], BB[1]);
	// printf("C: %d %d\n", CC[0], CC[1]);
	// printf("D: %d %d\n", DD[0], DD[1]);
	// printf("E: %d %d\n", EE[0], EE[1]);
	// printf("F: %d %d\n", FF[0], FF[1]);
	// printf("G: %d %d\n", GG[0], GG[1]);
	// printf("H: %d %d\n", HH[0], HH[1]);

	// DRAW THE POINTS TO THE MAP


	// ft_put_points_2d(&map, test);
	// ft_put_points_2d(&map, AA);
	// ft_put_points_2d(&map, BB);
	// ft_put_points_2d(&map, CC);
	// ft_put_points_2d(&map, DD);
	// ft_put_points_2d(&map, EE);
	// ft_put_points_2d(&map, FF);
	// ft_put_points_2d(&map, GG);
	// ft_put_points_2d(&map, HH);

	// CONNECT THE POINTS

	// ft_bresenham(&map, AA, BB);
	// ft_bresenham(&map, AA, DD);
	// ft_bresenham(&map, CC, DD);
	// ft_bresenham(&map, DD, AA);

	int tt[2] = {20, 20};
	int t1[2] = {100, 20};
	int t2[2] = {100, 50};
	int t3[2] = {100, 100};
	int t4[2] = {50, 100};
	int t5[2] = {20, 100};

	ft_bresenham(&map, tt, t1);
	ft_bresenham(&map, tt, t2);
	ft_bresenham(&map, tt, t3);
	ft_bresenham(&map, tt, t4);			// incorrect slope
	ft_bresenham(&map, tt, t5);

	int qq[2] = {120, 120};
	int q1[2] = {240, 120};
	int q2[2] = {480, 240};
	int q3[2] = {480, 480};
	int q4[2] = {240, 480};
	int q5[2] = {120, 240};

	ft_bresenham(&map, q1, qq);			// ok
	ft_bresenham(&map, q2, qq);			// way off and vertical
	ft_bresenham(&map, q3, qq);			// way off and vertical
	ft_bresenham(&map, q4, qq);			// way off and horizontal
	ft_bresenham(&map, q5, qq);			// ok

	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(map.mlx, &keyboard_hook, &map);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
