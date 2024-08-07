
// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "include/fdf.h"
// #define SGN(_x) ((_x) >= 0 || -1)


void ft_init_map(t_glib *glib, t_map *map)
{
	map->data_s = 0;
	map->coors = 0;
	map->coors_tr = 0;
	map->mid_scr[0] = glib->x_size / 2;
	map->mid_scr[1] = glib->y_size / 2;
	map->rl = 0; // row length
	map->rc = 0; // row count
	map->step_xy = 10;
	map->step_z = -1;
	map->lx = 0; // lowest x coor
	map->ly = 0; // lowest y coor
	map->hx = 0; // lowest x coor
	map->hy = 0; // lowest y coor
}

void ft_init_glib(t_glib *glib)
{
	glib->x_size = 800;
	glib->y_size = 600;
}
void my_keyhook(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

int32_t main(int argc, char **argv)
{
	t_glib glib;
	t_map	map;

	mlx_t *mlx = mlx_init(800, 600, "MLX42 Library", true);
	if (!mlx)
		printf("Library not created\n");	//	TODO: remove printf

	// create and display the image
	mlx_image_t *img = mlx_new_image(mlx, 800, 600);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		printf("Image not created\n");	//	TODO: remove printf
	ft_init_glib(&glib);
	glib.mlx = mlx;
	glib.img = img;
	glib.map = &map;
	// set every pixel to white
	// memset(img->pixels, 255, img->width * img->height * sizeof (int32_t));
	ft_init_map(&glib, &map);
	ft_parse_map(&map, "map");

	ft_isometric_transformation(&map);
	ft_draw_line(&glib, &map);

	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(glib.mlx, &keyboard_hook, &glib);
	// mlx_key_hook(glib.mlx, &my_keyhook, NULL);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
