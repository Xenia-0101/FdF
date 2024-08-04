
// cmake ./MLX42 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B ./MLX42/build
// make -C ./MLX42/build -j4
// cc -Wall -Wextra -Werror -g example.c ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
//

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "fdf.h"
// #define SGN(_x) ((_x) >= 0 || -1)

void print_arr(char **arr)
{
	int i;
	i = 0;

	while(arr[i])
	{
		printf("%s", arr[i]);
		i++;
	}
	printf("\n");
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
	char *row;
	char *mapdata;
	int fd;
	int row_len;
	int row_count;
	fd = open("./test_maps/42.fdf", O_RDONLY);
	row = get_next_line(fd);
	mapdata = ft_strdup("");
	row_len = ft_strlen(row);
	row_count = 0;

	while(row != NULL)
	{
		// printf("%s", row);
		mapdata = ft_strjoin_free(mapdata, row);
		free(row);
		row = get_next_line(fd);
		row_count++;
	}

	close(fd);
	printf("\n%s\n\n", mapdata);
	printf("%d\n", ft_strlen("hello"));
	printf("%d\n", row_count);

	// Register a hook and pass mlx as an optional param before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(map.mlx, &keyboard_hook, &map);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
