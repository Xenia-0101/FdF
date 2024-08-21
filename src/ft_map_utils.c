/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:08:40 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/21 10:28:21 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_sh_x(t_glib *glib, t_point **c, float v);
void	ft_sh_y(t_glib *glib, t_point **c, float v);

void	ft_sh_x(t_glib *glib, t_point **c, float v)
{
	int	i;
	int	j;

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

void	ft_sh_y(t_glib *glib, t_point **c, float v)
{
	int	i;
	int	j;

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
