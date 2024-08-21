/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:03:55 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/21 12:28:01 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// http://fredericgoset.ovh/mathematiques/courbes/en/bresenham_line.html

#include "include/fdf.h"

static int	ft_file_correct(char *file)
{
	int	fl;

	fl = ft_strlen(file);
	if (file[fl - 1] != 'f' || file[fl - 2] != 'd'
		|| file[fl - 3] != 'f' || file[fl - 4] != '.')
		return (0);
	return (1);
}

static void	ft_fdf_exit(t_glib *glib)
{
	mlx_delete_image(glib->mlx, glib->img);
	mlx_terminate(glib->mlx);
	ft_fdf_free(glib);
}

static void	ft_fdf_run(t_glib *glib)
{
	ft_map_transform(glib);
	ft_map_draw(glib);
	mlx_key_hook(glib->mlx, &keyboard_hook, glib);
	mlx_loop(glib->mlx);
}

int32_t	main(int argc, char **argv)
{
	t_glib	glib;
	t_map	map;
	char	*file;

	if (argc != 2)
		return (EXIT_FAILURE);
	file = argv[1];
	if (!ft_file_correct(file))
		return (EXIT_FAILURE);
	ft_fdf_init_glib(&glib, &map);
	if (!ft_map_parse(&glib, file))
		return (EXIT_FAILURE);
	glib.mlx = mlx_init(glib.x, glib.y, "MLX42 Library", true);
	if (!glib.mlx)
		return (EXIT_FAILURE);
	glib.img = mlx_new_image(glib.mlx, glib.x, glib.y);
	if (!glib.img || (mlx_image_to_window(glib.mlx, glib.img, 0, 0) < 0))
		return (EXIT_FAILURE);
	ft_fdf_run(&glib);
	ft_fdf_exit(&glib);
	return (EXIT_SUCCESS);
}
