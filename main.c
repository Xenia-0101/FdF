
// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "include/fdf.h"
// #define SGN(_x) ((_x) >= 0 || -1)





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
		printf("***%d\n", i);
	}
}

void ft_read_map(t_map *map, char *file)
{

	char *row;
	char *mapdata;
	int fd;

	int pull = 10;
	int shift = 200;


	fd = open("./test_maps/42.fdf", O_RDONLY);		// TODO: Change to file name !!
	row = get_next_line(fd);
	mapdata = ft_strdup("");
	map->rl = ft_strlen(row);
	map->rc = 0;

	while(row != NULL)
	{
		mapdata = ft_strjoin_free(mapdata, row);
		free(row);
		row = get_next_line(fd);
		map->rc++;
	}

	close(fd);
	// printf("\n%s\n\n", mapdata);
	// printf("%d\n", map->rc);
	map->data_s = ft_split(mapdata, '\n');
	free(mapdata);
	// printf("%s\n", map->data_s[3]);

	// create an array of coordinates
	int i = 0;
	int j;
	char **vals;
	map->coors = (t_point **)ft_calloc(map->rc + 1, sizeof (t_point *));
	if (map->coors == NULL)			// TODO: Error handling
	{
		return ;
	}
	while (i < map->rc)
	{
		vals = ft_split(map->data_s[i], ' ');
		map->coors[i] = (t_point *)ft_calloc(map->rl + 1, sizeof (t_point));
		if (map->coors == NULL)		// TODO: Error handling
		{
			// TODO: free and exit
			return ;
		}
		j = 0;
		while (vals[j])
		{
			map->coors[i][j].x = j * pull + 2*shift;
			map->coors[i][j].y = i * pull + shift;
			map->coors[i][j].z = ft_atoi(vals[j]) * pull / 2;
			j++;
		}
		map->rl = j;
		i++;
	}

	// printf("%d %d %d\n", map->coors[0][0].x, map->coors[0][0].y, map->coors[0][0].z);
	// printf("%d %d %d\n", map->coors[1][1].x, map->coors[1][1].y, map->coors[1][1].z);
	// printf("%d %d %d\n", map->coors[2][2].x, map->coors[2][2].y, map->coors[2][2].z);
	// printf("%d %d %d\n", map->coors[3][3].x, map->coors[3][3].y, map->coors[3][3].z);
	// printf("%d %d %d\n", map->coors[4][4].x, map->coors[4][4].y, map->coors[4][4].z);
	// printf("%d %d %d\n", map->coors[7][10].x, map->coors[7][10].y, map->coors[7][10].z);

	// print points to the map in 2d


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

	glib.mlx = mlx;
	glib.img = img;
	// set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof (int32_t));

	ft_read_map(&map, "map");
	ft_draw_points(&glib, &map);
	ft_draw_line(&glib, &map);

	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(glib.mlx, &keyboard_hook, &glib);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
