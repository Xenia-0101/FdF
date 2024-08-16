/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:53:50 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/16 16:48:09 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void keyboard_hook(mlx_key_data_t keydata, void *param)
{
	t_glib	*glib;
	size_t	i;

	glib = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(glib->mlx);
		return ;
	}
	if ((keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		ft_manipulate_img(glib, 'x', -5);
	}
	if ((keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		ft_manipulate_img(glib, 'x', 5);
	}
	if ((keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		ft_manipulate_img(glib, 'y', 5);
	}
	if ((keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		ft_manipulate_img(glib, 'y', -5);
	}
	if ((keydata.key == MLX_KEY_KP_ADD && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		ft_manipulate_img(glib, '+', 1.1);
	}
	if ((keydata.key == MLX_KEY_KP_SUBTRACT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		ft_manipulate_img(glib, '-', 0.9);
	}
	if ((keydata.key == MLX_KEY_Z && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		ft_manipulate_img(glib, 'z', 1.1);
	}
	if ((keydata.key == MLX_KEY_X && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		ft_manipulate_img(glib, 'z', 0.9);
	}
	if ((keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		ft_manipulate_img(glib, 'a', 5);
	}
	// if ((keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	// {
	// 	ft_manipulate_img(glib, 'z', 0.9);
	// }
	// printf("[%f; %.1f]\n", glib->map->coors_tr[0][glib->map->rl-1].x, glib->map->coors_tr[0][glib->map->rl-1].y);


}




