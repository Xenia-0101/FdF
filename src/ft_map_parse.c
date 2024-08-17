/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:26:16 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/17 19:09:02 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_free_row(char **row, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		free(row[i]);
		i++;
	}
	free(row);
}

static void ft_map_read(t_map *map, int fd)
{
	char *row;
	char *mapdata;

	row = get_next_line(fd);
	mapdata = ft_strdup("");
	map->rl = ft_count_spaces(row);
	map->rc = 0;
	while(row != NULL)
	{
		mapdata = ft_strjoin_free(mapdata, row);
		free(row);
		row = get_next_line(fd);
		map->rc++;
	}
	map->data_s = ft_split(mapdata, '\n');
	free(mapdata);
}

static int ft_allocate_coors(t_glib *glib)
{
	t_map *map;
	int i;

	map = glib->map;
	i = 0;
	if (!(map->coors = (t_point **)ft_calloc(map->rc, sizeof (t_point *))))
		return (0);
	if (!(map->coors_tr = (t_point **)ft_calloc(map->rc, sizeof (t_point *))))
		return (0);
	while (i < map->rc)
	{
		if (!(map->coors[i] = (t_point *)ft_calloc(map->rl, sizeof (t_point))))
			return (0);
		if (!(map->coors_tr[i] = (t_point *)ft_calloc(map->rl, sizeof (t_point))))
			return (0);
		i++;
	}
	return (1);
}

static void ft_map_to_point(t_glib *glib)
{
	int i;
	int	j;
	char **row;
	t_map *map = glib->map;

	i = 0;
	while (i < map->rc)
	{
		row = ft_split(map->data_s[i], ' ');
		j = 0;
		while (row[j])
		{
			map->coors[i][j].x = j - map->rl / 2;
			map->coors[i][j].y = i - map->rc / 2;
			map->coors[i][j].x = map->coors[i][j].x * map->step_xy + (glib->x / 2);
			map->coors[i][j].y = map->coors[i][j].y * map->step_xy + (glib->x / 2);
			map->coors[i][j].z = ft_atoi(row[j]);
			j++;
		}
		ft_free_row(row, map->rl);
		i++;
	}
}

/// @brief Read file data, set map.coors to
///			coordinates with centre at the origin
/// @param glib - graphic library struct
/// @param file - file to be read
/// @return 1 on success, -1 on error
int ft_map_parse(t_glib *glib, char *file)
{
	char *folder;
	char *path;
	int f_len;
	int fd;
	t_map *map = glib->map;

	folder = ft_strdup("./test_maps/");
	path = ft_strjoin(folder, file);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	ft_map_read(map, fd);
	close(fd);
	if (!ft_allocate_coors(glib))
		return (0);
	ft_map_to_point(glib);
	free(folder);
	free(path);
	return (1);
}
