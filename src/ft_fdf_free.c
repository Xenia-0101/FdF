/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:36:53 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/21 12:16:25 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_fdf_free(t_glib *glib);
void		ft_free_map_data_s(t_map *map);
static void	ft_free_coors_tr(t_map *map);
static void	ft_free_coors(t_map *map);

void	ft_free_map_data_s(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rc)
	{
		free(map->data_s[i]);
		i++;
	}
	free(map->data_s);
}

static void	ft_free_coors(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rc)
	{
		map->coors[i]->x = 0;
		map->coors[i]->y = 0;
		map->coors[i]->z = 0;
		free(map->coors[i]);
		i++;
	}
	free(map->coors);
}

static void	ft_free_coors_tr(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rc)
	{
		map->coors_tr[i]->x = 0;
		map->coors_tr[i]->y = 0;
		map->coors_tr[i]->z = 0;
		free(map->coors_tr[i]);
		i++;
	}
	free(map->coors_tr);
}

void	ft_fdf_free(t_glib *glib)
{
	glib->x = 0;
	glib->y = 0;
	ft_free_map_data_s(glib->map);
	ft_free_coors(glib->map);
	ft_free_coors_tr(glib->map);
}
