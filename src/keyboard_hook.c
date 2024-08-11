/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:53:50 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/11 11:20:38 by xvislock         ###   ########.fr       */
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
		glib->map->step_x -= 5;
		ft_reset_img(glib);
		ft_isometric_transformation(glib->map);
		ft_map_shift(glib);
		ft_draw(glib, glib->map);
	}
	if ((keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		glib->map->step_x += 5;
		ft_reset_img(glib);
		ft_isometric_transformation(glib->map);
		ft_map_shift(glib);
		ft_draw(glib, glib->map);
	}
	if ((keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		glib->map->step_y += 5;
		ft_reset_img(glib);
		ft_isometric_transformation(glib->map);
		ft_map_shift(glib);
		ft_draw(glib, glib->map);
	}
	if ((keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		glib->map->step_y -= 5;
		ft_reset_img(glib);
		ft_isometric_transformation(glib->map);
		ft_map_shift(glib);
		ft_draw(glib, glib->map);
	}
	if ((keydata.key == MLX_KEY_KP_ADD && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		glib->map->step_xy += 0.5;
		ft_reset_img(glib);
		ft_isometric_transformation(glib->map);
		ft_map_shift(glib);
		ft_draw(glib, glib->map);
	}
	if ((keydata.key == MLX_KEY_KP_SUBTRACT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		glib->map->step_xy -= 0.5;
		ft_reset_img(glib);
		ft_isometric_transformation(glib->map);
		ft_map_shift(glib);
		ft_draw(glib, glib->map);
	}
	if ((keydata.key == MLX_KEY_Z && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		glib->map->step_z += 0.1;
		ft_reset_img(glib);
		ft_isometric_transformation(glib->map);
		ft_map_shift(glib);
		ft_draw(glib, glib->map);
	}
	if ((keydata.key == MLX_KEY_X && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)))
	{
		glib->map->step_z -= 0.1;
		ft_reset_img(glib);
		ft_isometric_transformation(glib->map);
		ft_map_shift(glib);
		ft_draw(glib, glib->map);
	}
	// printf("[%f; %.1f]\n", glib->map->coors_tr[0][glib->map->rl-1].x, glib->map->coors_tr[0][glib->map->rl-1].y);


}




