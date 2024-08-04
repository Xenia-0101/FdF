
// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "fdf.h"
// #define SGN(_x) ((_x) >= 0 || -1)

int *ft_transform_2d(int p3[3], int p2[2])
{
	p2[0] = p3[0] * cos(120) + p3[1] * cos(122) + p3[2] * cos(118);
	p2[1] = p3[0] * sin(120) + p3[1] * sin(122) + p3[2] * sin(118);
	return (p2);
}
void draw_cube(t_map *map)
{
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

		ft_transform_2d(A, AA);
		ft_transform_2d(B, BB);
		ft_transform_2d(C, CC);
		ft_transform_2d(D, DD);
		ft_transform_2d(E, EE);
		ft_transform_2d(F, FF);
		ft_transform_2d(G, GG);
		ft_transform_2d(H, HH);

		// DRAW THE POINTS TO THE MAP

		ft_put_points_2d(map, test);
		ft_put_points_2d(map, AA);
		ft_put_points_2d(map, BB);
		ft_put_points_2d(map, CC);
		ft_put_points_2d(map, DD);
		ft_put_points_2d(map, EE);
		ft_put_points_2d(map, FF);
		ft_put_points_2d(map, GG);
		ft_put_points_2d(map, HH);

		// CONNECT THE POINTS

		ft_bresenham(map, AA, BB);
		ft_bresenham(map, BB, CC);
		ft_bresenham(map, CC, DD);
		ft_bresenham(map, DD, AA);
		ft_bresenham(map, EE, FF);
		ft_bresenham(map, FF, GG);
		ft_bresenham(map, GG, HH);
		ft_bresenham(map, HH, EE);
		ft_bresenham(map, EE, AA);
		ft_bresenham(map, FF, BB);
		ft_bresenham(map, GG, CC);
		ft_bresenham(map, HH, DD);
}

int32_t main(int argc, char **argv)
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

	// reading a file
	// char *res;
	// int fd;
	// fd = open("./test_maps/42.fdf", O_RDONLY);

	// res = get_next_line(fd);
	// while(res != NULL)
	// {
	// 	printf("%s", res);
	// 	free(res);
	// 	res = get_next_line(fd);
	// }
	// close(fd);

	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(map.mlx, &keyboard_hook, &map);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
