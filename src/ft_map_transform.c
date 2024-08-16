/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_transform.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:58:29 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/14 20:03:24 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_map_transform(t_glib *glib)
{
	printf("Isometric transformation...\n");
	t_map *map;
	int i;
	int j;

	map = glib->map;
	i = 0;
	if (!(map->coors_tr = (t_point **)ft_calloc(map->rc, sizeof (t_point *))))
		return (-1);
	while (i < map->rc)
	{
		if (!(map->coors_tr[i] = (t_point *)ft_calloc(map->rl, sizeof (t_point))))
			return (-1);
		j = 0;
		while (j < map->rl)
		{
			ft_pnt_by_mtrx(map->coors[i][j], &(map->coors_tr[i][j]), glib->isoR);
			map->coors_tr[i][j].z = map->coors[i][j].z;		// keep z the same for z manipulation and repeated calculation
			printf("%4.1f ", map->coors_tr[i][j].x);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	return (1);
}

