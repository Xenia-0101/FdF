
// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "include/fdf.h"
// #define SGN(_x) ((_x) >= 0 || -1)

static void ft_coors_tr_allocate(t_map *map)
{
	int i;

	map->coors_tr = (t_point_d **)ft_calloc(map->rc + 1, sizeof (t_point_d *));
	i = 0;
	while (i < map->rc)
	{
		map->coors_tr[i] = (t_point_d *)ft_calloc(map->rl + 1, sizeof (t_point_d));
		i++;
	}
}

static void ft_coors_allocate(t_map *map)
{
	int i;

	map->coors = (t_point **)ft_calloc(map->rc + 1, sizeof (t_point *));
	i = 0;
	while (i < map->rc)
	{
		map->coors[i] = (t_point *)ft_calloc(map->rl + 1, sizeof (t_point));
		i++;
	}
}

void ft_draw_points(t_glib *glib, t_map *map)
{
	int i;
	int j;
	int point[3];

	i = 0;
	printf("%d\n", map->rc);
	while (i < map->rc)
	{
		j = 0;
		while (j < map->rl)
		{
			point[0] = map->coors[i][j].x;
			point[1] = map->coors[i][j].y;
			point[2] = map->coors[i][j].z;
			ft_put_points_3d(glib, point);
			j++;
		}
		i++;
	}
}

static int ft_count_spaces(char *s)
{
	int i;
	int c;

	i = 0;
	c = 1;
	while (s[i])
	{
		printf("%c", s[i]);
		if (s[i] == ' ')
		{
			c++;
			while(s[i] == ' ')
				i++;
		}
		i++;
	}
	return (c);
}

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
	map->step_z = 2;
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

void ft_read_map(t_map *map, char *file)
{
	char *row;
	char *mapdata;
	int fd;

	fd = open("./test_maps/42.fdf", O_RDONLY);		// TODO: Change to file name !!
	row = get_next_line(fd);
	mapdata = ft_strdup("");
	map->rl = ft_count_spaces(row);
	map->rc = 0;
	while(row != NULL)
	{
		mapdata = ft_strjoin_free(mapdata, row);
		free(row);
		row = get_next_line(fd);
		map->rc++;
	}
	close(fd);
	map->data_s = ft_split(mapdata, '\n');
	free(mapdata);
}

void ft_parse_map(t_map *map, char *file)
{

	ft_read_map(map, file);
	ft_coors_allocate(map);
	ft_coors_tr_allocate(map);

	// create an array of coordinates
	int i = 0;
	int j;
	char **vals;

	if (map->coors == NULL)			// TODO: Error handling
	{
		return ;
	}
	while (i < map->rc)
	{
		vals = ft_split(map->data_s[i], ' ');
		if (map->coors == NULL)		// TODO: Error handling
		{
			// TODO: free and exit
			return ;
		}
		j = 0;
		while (vals[j])
		{
			map->coors[i][j].x = j * map->step_xy;
			map->coors[i][j].y = i * map->step_xy;
			map->coors[i][j].z = ft_atoi(vals[j]) * map->step_z;
			j++;
		}
		map->rl = j;
		i++;
	}
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
	// set every pixel to white
	// memset(img->pixels, 255, img->width * img->height * sizeof (int32_t));
	ft_init_map(&glib, &map);
	ft_parse_map(&map, "map");
	ft_isometric_transformation(&map);
	// ft_draw_points(&glib, &map);
	ft_draw_line(&glib, &map);

	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(glib.mlx, &keyboard_hook, &glib);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
