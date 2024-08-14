/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:03:55 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/14 20:15:24 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "include/fdf.h"

// **** INIT FUNCTIONS **** //
void ft_init_glib_isoR(t_glib *glib)
{
	glib->isoR[0][0] = sqrt(2) / 2;
	glib->isoR[0][1] = -sqrt(2) / 2;
	glib->isoR[0][2] = 0;

	glib->isoR[1][0] = sqrt(6) / 6;
	glib->isoR[1][1] = sqrt(6) / 6;
	glib->isoR[1][2] = -sqrt(6) / 3;

	glib->isoR[2][0] = sqrt(3) / 3;
	glib->isoR[2][1] = sqrt(3) / 3;
	glib->isoR[2][2] = sqrt(3) / 3;
}
void ft_init_glib(t_glib *glib)
{
	glib->mlx = 0;
	glib->img = 0;
	glib->map = 0;
	ft_init_glib_isoR(glib);
	glib->x = 800;
	glib->y = 600;
}
void ft_init_map(t_map *map)
{
	map->data_s = 0;
	map->data_i = 0;
	map->coors = 0;
	map->coors_tr = 0;
	map->rl = 0;
	map->rc = 0;
	map->step_xy = 10;
	map->step_z = 0.1;
	map->sh_x = 0;
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
	ft_free_coors(map);
	ft_free_coors_tr(map);
}

void ft_free_glib(t_glib *glib)
{
	glib->x = glib->y = 0;
}

void ft_sh_x(t_glib *glib, float v)
{
	t_point **c = glib->map->coors_tr;
	int i;
	int j;
	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			c[i][j].x += v;
			j++;
		}
		i++;
	}
}

void ft_sh_y(t_glib *glib, float v)
{
	t_point **c = glib->map->coors_tr;
	int i;
	int j;
	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			c[i][j].y += v;
			j++;
		}
		i++;
	}
}

void ft_zoom_in(t_glib *glib, float v)
{
	t_map *map = glib->map;
	t_point **c = glib->map->coors_tr;
	int i;
	int j;
	double mid_x;
	double mid_y;
	double const_x;
	double const_y;

	mid_x = glib->x / 2 - map->coors_tr[map->rc / 2][map->rl / 2].x;
	mid_y = glib->y / 2 - map->coors_tr[map->rc / 2][map->rl / 2].y;
	const_x = (0.1 * glib->x / 2 + mid_x);
	const_y = (0.1 * glib->y / 2 + mid_y);
	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			c[i][j].x = (c[i][j].x + mid_x) * v - const_x;
			c[i][j].y = (c[i][j].y + mid_y) * v - const_y;
			j++;
		}
		i++;
	}
}
void ft_zoom_out(t_glib *glib, float v)
{
	t_map *map = glib->map;
	t_point **c = glib->map->coors_tr;
	int i;
	int j;
	double mid_x;
	double mid_y;
	double const_x;
	double const_y;

	mid_x = glib->x / 2 - map->coors_tr[map->rc / 2][map->rl / 2].x;
	mid_y = glib->y / 2 - map->coors_tr[map->rc / 2][map->rl / 2].y;
	const_x = mid_x - (glib->x / 2 - (glib->x / 2) * v);
	const_y = mid_y - (glib->y / 2 - (glib->y / 2) * v);
	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			c[i][j].x = (c[i][j].x + mid_x) * v - const_x;
			c[i][j].y = (c[i][j].y + mid_y) * v - const_y;
			j++;
		}
		i++;
	}
}

void ft_str_z(t_glib *glib, float v)
{
	// change z in coors
	// calculate projection
	t_map *map = glib->map;
	int i;
	int j;
	double mid_x;
	double mid_y;
	mid_x = glib->x / 2 - map->coors_tr[map->rc / 2][map->rl / 2].x;
	mid_y = glib->y / 2 - map->coors_tr[map->rc / 2][map->rl / 2].y;

	i = 0;
	while (i < glib->map->rc)
	{
		j = 0;
		while (j < glib->map->rl)
		{
			map->coors[i][j].z *= v;
			ft_point_matrix(map->coors[i][j], &(map->coors_tr[i][j]), glib->isoR);
			printf("%.1f ", map->coors_tr[i][j].x);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_point_shift(glib);
	ft_sh_x(glib, -mid_x);
	ft_sh_y(glib, -mid_y);
	// shift to original place
}

void ft_manipulate_img(t_glib *glib, char o, float v)
{
	// manipulate img based on operation and value passed
	if (o == 'x')
	{
		ft_sh_x(glib, v);
	}
	if (o == 'y')
	{
		ft_sh_y(glib, v);
	}
	if (o == '+')
	{
		ft_zoom_in(glib, v);
	}
	if (o == '-')
	{
		ft_zoom_out(glib, v);
	}
	if (o == 'z')
	{
		ft_str_z(glib, v);
	}
	memset(glib->img->pixels, 0x00, glib->img->width * glib->img->height * sizeof (int32_t));
	ft_draw(glib, glib->map);
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
	ft_isometric_transformation(&glib);

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
