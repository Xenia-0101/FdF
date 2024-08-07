/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:53:50 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/07 19:24:11 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

typedef struct s_key_glib
{
	char		*key_val;
	enum keys	key_act;
}	t_key_glib;

t_key_glib keyboard[] = {
	{"a", MLX_KEY_A},
	{"b", MLX_KEY_B},
	{"c", MLX_KEY_C},
	{"d", MLX_KEY_D},
	{"e", MLX_KEY_E},
	{"f", MLX_KEY_F},
	{"g", MLX_KEY_G},
	{"h", MLX_KEY_H},
	{"i", MLX_KEY_I},
	{"j", MLX_KEY_J},
	{"k", MLX_KEY_K},
	{"l", MLX_KEY_L},
	{"m", MLX_KEY_M},
	{"n", MLX_KEY_N},
	{"o", MLX_KEY_O},
	{"p", MLX_KEY_P},
	{"q", MLX_KEY_Q},
	{"r", MLX_KEY_R},
	{"s", MLX_KEY_S},
	{"t", MLX_KEY_T},
	{"u", MLX_KEY_U},
	{"v", MLX_KEY_V},
	{"w", MLX_KEY_W},
	{"x", MLX_KEY_X},
	{"y", MLX_KEY_Y},
	{"z", MLX_KEY_Z},
	{" ", MLX_KEY_SPACE},
	{"0", MLX_KEY_0},
	{"1", MLX_KEY_1},
	{"2", MLX_KEY_2},
	{"3", MLX_KEY_3},
	{"4", MLX_KEY_4},
	{"5", MLX_KEY_5},
	{"6", MLX_KEY_6},
	{"7", MLX_KEY_7},
	{"8", MLX_KEY_8},
	{"9", MLX_KEY_9},
};

void keyboard_hook(mlx_key_data_t keydata, void *param)
{
	t_glib	*glib;
	size_t	i;

	glib = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(glib->mlx);
	}
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
	{
		glib->map->step_z++;
		ft_parse_map(glib->map, "map");

		memset(glib->img->pixels, 0, glib->img->width * glib->img->height * sizeof (int32_t));
		ft_isometric_transformation(glib->map);
		ft_draw_line(glib, glib->map);
	}
	// else if (mlx_is_key_down(glib->mlx, MLX_KEY_Q))
	else
	{
		i = 0;
		while (i < sizeof (keyboard) / sizeof (keyboard[0]))
		{
			if (keydata.key == keyboard[i].key_act && keydata.action == MLX_PRESS)
				puts(keyboard[i].key_val);
			i++;
		}
	}

}




