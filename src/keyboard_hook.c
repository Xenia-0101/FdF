/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:53:50 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 13:30:14 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	keyboard_hook_1(mlx_key_data_t key, t_glib *glib)
{
	if (key.key == MLX_KEY_LEFT)
		ft_map_recalc(glib, 'x', -5);
	if (key.key == MLX_KEY_RIGHT)
		ft_map_recalc(glib, 'x', 5);
	if (key.key == MLX_KEY_DOWN)
		ft_map_recalc(glib, 'y', 5);
	if (key.key == MLX_KEY_UP)
		ft_map_recalc(glib, 'y', -5);
	if (key.key == MLX_KEY_KP_ADD)
		ft_map_recalc(glib, '+', 0.1);
	if (key.key == MLX_KEY_KP_SUBTRACT)
		ft_map_recalc(glib, '+', -0.1);
	if (key.key == MLX_KEY_Z)
		ft_map_recalc(glib, 'z', 0.1);
	if (key.key == MLX_KEY_X)
		ft_map_recalc(glib, 'z', -0.1);
	if (key.key == MLX_KEY_A)
		ft_map_recalc(glib, 'a', 1);
	if (key.key == MLX_KEY_D)
		ft_map_recalc(glib, 'a', -1);
}

static void	keyboard_hook_2(mlx_key_data_t key, t_glib *glib)
{
	if (key.key == MLX_KEY_W)
		ft_map_recalc(glib, 'w', 1);
	if (key.key == MLX_KEY_S)
		ft_map_recalc(glib, 'w', -1);
	if (key.key == MLX_KEY_Q)
		ft_map_recalc(glib, 'q', 1);
	if (key.key == MLX_KEY_E)
		ft_map_recalc(glib, 'q', -1);
	if (key.key == 321)		// numeric keyboard 1
		ft_map_recalc(glib, '1', 1);
	if (key.key == 327)		// numeric keyboard 7
		ft_map_recalc(glib, '7', 1);
	if (key.key == 328)		// numeric keyboard 8
		ft_map_recalc(glib, '7', -1);
	if (key.key == 324)		// numeric keyboard 4
		ft_map_recalc(glib, '4', 10);
	if (key.key == 325)		// numeric keyboard 5
		ft_map_recalc(glib, '4', -10);
}

void	keyboard_hook(mlx_key_data_t key, void *param)
{
	t_glib	*glib;

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
