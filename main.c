/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:03:55 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 11:03:32 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "include/fdf.h"

int32_t main(int argc, char **argv)
{
	int fl;
	char *file;
	t_glib glib;
	t_map	map;
	t_change d;

	if (argc != 2)
		return (EXIT_FAILURE);
	file = argv[1];
	fl = ft_strlen(file);
	if (file[fl - 1] != 'f' || file[fl - 2] != 'd' || file[fl - 3] != 'f' || file[fl - 4] != '.')
		return (EXIT_FAILURE);

	ft_fdf_init_glib(&glib);
	map.dd = d;
	ft_fdf_init_map(&map);

	glib.mlx = mlx_init(glib.x, glib.y, "MLX42 Library", true);
	if (!glib.mlx)
		printf("Library not created\n");	//	TODO: remove printf

	// create and display the image
	glib.img = mlx_new_image(glib.mlx, glib.x, glib.y);
	if (!glib.img || (mlx_image_to_window(glib.mlx, glib.img, 0, 0) < 0))
		printf("Image not created\n");	//	TODO: remove printf

	glib.map = &map;

	// **** THE MAGIC **** //

	// parse the map
	ft_map_parse(&glib, file);

	// transform coordinates
	ft_map_transform(&glib);

	// // display data
	ft_map_draw(&glib);

	// **** **** **** **** //

	mlx_key_hook(glib.mlx, &keyboard_hook, &glib);
	mlx_loop(glib.mlx);
	mlx_delete_image(glib.mlx, glib.img);
	mlx_terminate(glib.mlx);
	ft_fdf_free(&glib);
	return (EXIT_SUCCESS);
}
