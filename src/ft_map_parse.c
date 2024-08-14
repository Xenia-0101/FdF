/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:26:16 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/14 18:00:49 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int ft_count_spaces(char *s)
{
	int i;
	int c;

	i = 0;
	c = 1;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			c++;
			while(s[i] == ' ')
				i++;
		}
		i++;
	}
	return (c);
}

static int ft_map_read(t_map *map, int fd)
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
	return (1);
}

void ft_free_row(char **row, int l)
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

static int ft_map_to_point(t_glib *glib)
{
	printf("Map to point...\n");
	int i;
	int	j;
	char **row;
	t_map *map = glib->map;

	i = 0;
	if (!(map->coors = (t_point **)ft_calloc(map->rc, sizeof (t_point *))))
		return (-1);
	while (i < map->rc)
	{
		if (!(map->coors[i] = (t_point *)ft_calloc(map->rl, sizeof (t_point))))
			return (-1);
		row = ft_split(map->data_s[i], ' ');
		j = 0;
		while (row[j])
		{
			map->coors[i][j].x = j;
			map->coors[i][j].y = i;
			map->coors[i][j].z = ft_atoi(row[j]) * map->step_z;
			printf("%4.1f ", map->coors[i][j].x);
			j++;
		}
		printf("\n");
		ft_free_row(row, map->rl);		// ToDo: free an array of arrays !!!
		i++;
	}
	printf("\n");
	return (1);
}

int ft_map_parse(t_glib *glib, char *file)
{
	char *folder;
	char *path;
	int f_len;
	int fd;
	t_map *map = glib->map;

	folder = ft_strdup("./test_maps/");
	path = ft_strjoin(folder, file);
	printf("%s\n", path);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	ft_map_read(map, fd);
	close(fd);
	ft_map_to_point(glib);
	free(folder);
	free(path);
	return (1);
}
