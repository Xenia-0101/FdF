/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:02:32 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/07 19:29:02 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// Allocate memory for map->coors_tr (Transformed coordinates)
// Requires map->rl and map->rc values to be set correctly
static void ft_coors_tr_allocate(t_map *map)
{
	int i;

	map->coors_tr = (t_point_d **)ft_calloc(map->rc + 1, sizeof (t_point_d *));
	if (map->coors_tr == NULL)			// TODO: Error handling
	{
		return ;		// ToDo: Exit safely
	}
	i = 0;
	while (i < map->rc)
	{
		map->coors_tr[i] = (t_point_d *)ft_calloc(map->rl + 1, sizeof (t_point_d));
		i++;
	}
}
// Allocates memory for map->coors
// Requires map->rl and map->rc values to be set correctly
static void ft_coors_allocate(t_map *map)
{
	int i;

	map->coors = (t_point **)ft_calloc(map->rc + 1, sizeof (t_point *));
	if (map->coors == NULL)			// TODO: Error handling
	{
		return ;		// ToDo: Exit safely
	}
	i = 0;
	while (i < map->rc)
	{
		map->coors[i] = (t_point *)ft_calloc(map->rl + 1, sizeof (t_point));
		i++;
	}
}

static int ft_count_spaces(char *s)
{
	int i;
	int c;

	i = 0;
	c = 1;
	while (s[i])
	{
		printf("%c", s[i]);
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

// ******
// Parse the map and store the result in map->data_s (The format: an array of strings/lines)
// Modified vars: map->rl, map->rc, map->data_s
// Input: *map, *file - full name of the map file
// Output: Void
// ******
//	open the map (file)
//	get the first line
//		set values to row length and row count
//	read form the file and joint the lines to create one long string with lines separated by \n
//	assign to map->data_s: an array of strings
// ******
static void ft_read_map(t_map *map, char *file)
{
	char *row;
	char *mapdata;
	int fd;

	fd = open("./test_maps/elem2.fdf", O_RDONLY);		// TODO: Change to file name !!
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
	close(fd);
	map->data_s = ft_split(mapdata, '\n');
	free(mapdata);
}

void ft_calculate_coors(t_map *map, char *file)
{
	int i = 0;
	int j;
	char **vals;

	while (i < map->rc)
	{
		vals = ft_split(map->data_s[i], ' ');
		j = 0;
		while (vals[j])
		{
			map->coors[i][j].x = j * map->step_xy;
			map->coors[i][j].y = i * map->step_xy;
			map->coors[i][j].z = ft_atoi(vals[j]) * map->step_z;
			j++;
		}
		free(vals);
		i++;
	}
}

// Transform the file data into xyz coordinates, store the result in map->coors
// Input: *map, *file
void ft_parse_map(t_map *map, char *file)
{
	ft_read_map(map, file);
	ft_coors_allocate(map);
	ft_coors_tr_allocate(map);
	ft_calculate_coors(map, file);

	// create an array of coordinates

}
