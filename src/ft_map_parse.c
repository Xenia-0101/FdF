/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:26:16 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/12 18:21:25 by xenia            ###   ########.fr       */
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

static int ft_map_to_int(t_map *map)
{
	int i;
	int	j;
	char **row;

	i = 0;
	if (!(map->data_i = (int **)ft_calloc(map->rc, sizeof (int *))))
		return (-1);
	while (i < map->rc)
	{
		if (!(map->data_i[i] = (int *)ft_calloc(map->rl, sizeof (int))))
			return (-1);
		row = ft_split(map->data_s[i], ' ');
		j = 0;
		while (row[j])
		{
			map->data_i[i][j] = ft_atoi(row[j]);
			j++;
		}
		ft_free_row(row, map->rl);		// ToDo: free an array of arrays !!!
		i++;
	}
	return (1);
}

int ft_map_parse(t_map *map, char *file)
{
	char *folder;
	char *path;
	int f_len;
	int fd;

	folder = ft_strdup("./test_maps/");
	path = ft_strjoin(folder, file);
	printf("%s\n", path);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	ft_map_read(map, fd);
	close(fd);
	ft_map_to_int(map);
	free(folder);
	free(path);
	return (1);
}
