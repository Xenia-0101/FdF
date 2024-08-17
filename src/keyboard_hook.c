/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:53:50 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/17 20:01:11 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void keyboard_hook_1(mlx_key_data_t key, t_glib *glib)
{
	if (key.key == MLX_KEY_LEFT)
		ft_manipulate_img(glib, 'x', -5);
	if (key.key == MLX_KEY_RIGHT)
		ft_manipulate_img(glib, 'x', 5);
	if (key.key == MLX_KEY_DOWN)
		ft_manipulate_img(glib, 'y', 5);
	if (key.key == MLX_KEY_UP)
		ft_manipulate_img(glib, 'y', -5);
	if (key.key == MLX_KEY_KP_ADD)
		ft_manipulate_img(glib, '+', 0.1);
	if (key.key == MLX_KEY_KP_SUBTRACT)
		ft_manipulate_img(glib, '+', -0.1);
	if (key.key == MLX_KEY_Z)
		ft_manipulate_img(glib, 'z', 0.1);
	if (key.key == MLX_KEY_X)
		ft_manipulate_img(glib, 'z', -0.1);
	if (key.key == MLX_KEY_A)
		ft_manipulate_img(glib, 'a', 1);
	if (key.key == MLX_KEY_D)
		ft_manipulate_img(glib, 'a', -1);
}

void keyboard_hook_2(mlx_key_data_t key, t_glib *glib)
{
	if (key.key == MLX_KEY_W)
		ft_manipulate_img(glib, 'w', 1);
	if (key.key == MLX_KEY_S)
		ft_manipulate_img(glib, 'w', -1);
	if (key.key == MLX_KEY_Q)
		ft_manipulate_img(glib, 'q', 1);
	if (key.key == MLX_KEY_E)
		ft_manipulate_img(glib, 'q', -1);
}

void keyboard_hook(mlx_key_data_t key, void *param)
{
	t_glib *glib;

	glib = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		mlx_close_window(glib->mlx);
		return ;
	}
	else if (key.action == 1 || key.action == 2)
	{
		keyboard_hook_1(key, glib);
		keyboard_hook_2(key, glib);
	}
}
