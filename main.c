/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:03:55 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/12 18:33:52 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "include/fdf.h"

// **** INIT FUNCTIONS **** //
void ft_init_glib(t_glib *glib)
{
	glib->mlx = 0;
	glib->img = 0;
	glib->x_size = 800;
	glib->y_size = 600;
	glib->map = 0;
}
void ft_init_map(t_map *map)
{
	map->data_s = 0;
	map->data_i = 0;
	map->coors = 0;
	map->coors_tr = 0;
	map->mid_scr[0] = 0;
	map->mid_scr[1] = 0;
	map->rl = 0;
	map->rc = 0;
	map->step_xy = 10;
	map->step_z = 0.1;
	map->step_x = 0;
	map->step_y = 0;
	map->step_zoom = 1;
	map->lx = 0;
	map->ly = 0;
	map->hx = 0;
	map->hy = 0;
}
void ft_free_map_data_s(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->rc)
	{
		free(map->data_s[i]);
		i++;
	}
	free(map->data_s);
}
void ft_free_map_data_i(t_map *map)
{
	int i;

	i = 0;
	while (i < map->rc)
	{
		free(map->data_i[i]);
		i++;
	}
	free(map->data_i);
}

void ft_free_coors(t_map *map)
{
	int i;

	i = 0;
	while (i < map->rc)
	{
		map->coors[i]->x = 0;
		map->coors[i]->y = 0;
		map->coors[i]->z = 0;
		free(map->coors[i]);
		i++;
	}
	free(map->coors);
}

void ft_free_coors_tr(t_map *map)
{
	int i;

	i = 0;
	while (i < map->rc)
	{
		map->coors_tr[i]->x = 0;
		map->coors_tr[i]->y = 0;
		map->coors_tr[i]->z = 0;
		free(map->coors_tr[i]);
		i++;
	}
	free(map->coors_tr);
}
void ft_free_map(t_map *map)
{
	ft_free_map_data_s(map);
	ft_free_map_data_i(map);
	ft_free_coors(map);
	ft_free_coors_tr(map);
}

void ft_free_glib(t_glib *glib)
{
	// free(glib->map);
	glib->x_size = glib->y_size = 0;
}

int32_t main(int argc, char **argv)
{
	int fl;
	char *file;
	t_glib glib;
	t_map	map;

	if (argc != 2)
		return (EXIT_FAILURE);
	file = argv[1];
	fl = ft_strlen(file);
	if (file[fl - 1] != 'f' || file[fl - 2] != 'd' || file[fl - 3] != 'f' || file[fl - 4] != '.')
		return (EXIT_FAILURE);

	ft_init_glib(&glib);
	ft_init_map(&map);

	glib.mlx = mlx_init(glib.x_size, glib.y_size, "MLX42 Library", true);
	if (!glib.mlx)
		printf("Library not created\n");	//	TODO: remove printf

	// create and display the image
	glib.img = mlx_new_image(glib.mlx, glib.x_size, glib.y_size);
	if (!glib.img || (mlx_image_to_window(glib.mlx, glib.img, 0, 0) < 0))
		printf("Image not created\n");	//	TODO: remove printf

	glib.map = &map;

	// **** THE MAGIC **** //

	// parse the map
	ft_map_parse(&map, file);

	// transform coordinates
	ft_isometric_transformation(&map);

	// coors transformations
	ft_map_shift(&glib);

	// display data
	ft_draw(&glib, &map);

	// **** **** **** **** //

	mlx_key_hook(glib.mlx, &keyboard_hook, &glib);
	mlx_loop(glib.mlx);
	mlx_delete_image(glib.mlx, glib.img);
	mlx_terminate(glib.mlx);
	ft_free_glib(&glib);
	ft_free_map(&map);
	return (EXIT_SUCCESS);
}
