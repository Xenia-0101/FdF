/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:26:16 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 22:00:12 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_map_parse(t_glib *glib, char *file);
static void	ft_map_read(t_map *map, int fd);
static void	ft_map_to_point(t_glib *glib);
static int	ft_allocate_coors(t_glib *glib);
static void	ft_free_row(char **row, int l);

/**
 * @brief Reads file data and creates coordinates for further data calculations.
 *
 * Creates a path string (./test_maps/file) and opens the file for reading.
 * If open function fails, folder and path char * are freed and
 * function returns 0.
 * Calls functions which read data and create coordinate for further
 * calculations.
 * Frees folder and path cahr *, returns 1 on success.
 *
 * @param glib	Data struct
 * @param file	Filename (has to be in test_maps folder)
 * @return int	1 on success, 0 on open file or memory allocation fail.
 */
int	ft_map_parse(t_glib *glib, char *file)
{
	char	*folder;
	char	*path;
	int		f_len;
	int		fd;

	folder = ft_strdup("./test_maps/");
	path = ft_strjoin(folder, file);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(folder);
		free(path);
		return (0);
	}
	ft_map_read(glib->map, fd);
	close(fd);
	if (!ft_allocate_coors(glib))
		return (0);
	ft_map_to_point(glib);
	free(folder);
	free(path);
	return (1);
}

/**
 * @brief Reads and formats data from file, stores the data in map.data_s.
 *
 * Using get_next_line function, the first row of data is read and
 * stored in row variable.
 * Based on the number of coordinates in the first row, the map.rl (row length)
 * is calculated. It is assumed all the rows have equal length.
 * Mapdata string is initialised as an empty string.
 * In the while loop, each new row is appended to mapdata, freed and read
 * into a new line. After each pass map.rc (row count) is increased.
 * When all has been read, mapdata is split by newline and the data is stored
 * as an array of strings in map.data_s variable.
 * At the end, mapdata is freed.
 *
 * @param map	Map struct
 * @param fd	File destriptor to be read from
 */
static void	ft_map_read(t_map *map, int fd)
{
	char	*row;
	char	*mapdata;

	row = get_next_line(fd);
	map->rl = ft_count_spaces(row);
	map->rc = 0;
	mapdata = ft_strdup("");
	while (row != NULL)
	{
		mapdata = ft_strjoin_free(mapdata, row);
		free(row);
		row = get_next_line(fd);
		map->rc++;
	}
	map->data_s = ft_split(mapdata, '\n');
	free(mapdata);
}

/**
 * @brief Transform map.data_s to map.coors centred around the screen centre.
 *
 * Iterates through map.data_s array, splits each row by space and
 * for each stirng in the row creates xyz coordinates:
 * - x and y are determined by the map.rc and map.rl values.
 * - z is taken as the numeric value at data_s[rc][rl].
 * The x and y data are modified as follows:
 * - shift img to the origin
	 		map->coors[i][j].x = j - map->rl / 2;
			map->coors[i][j].y = i - map->rc / 2;
 * - spread the points by map.step_xy
			map->coors[i][j].x = map->coors[i][j].x * map->step_xy;
			map->coors[i][j].y = map->coors[i][j].y * map->step_xy;
 * - shift img to the centre of the screen
			map->coors[i][j].x += (glib->x / 2);
			map->coors[i][j].y += (glib->x / 2);
 * After assigning each coordinate in the current row, the row variable is freed.

 * @param glib Data struct
 */
static void	ft_map_to_point(t_glib *glib)
{
	int		i;
	int		j;
	char	**row;
	t_map	*map;

	map = glib->map;
	// get first z from data_s -- color grad recording
	row = ft_split(map->data_s[0], ' ');
	map->lz = ft_atoi(row[0]);
	map->hz = ft_atoi(row[0]);
	ft_free_row(row, map->rl);
	i = 0;
	while (i < map->rc)
	{
		row = ft_split(map->data_s[i], ' ');
		j = 0;
		while (row[j])
		{
			map->coors[i][j].x = j - map->rl / 2;
			map->coors[i][j].y = i - map->rc / 2;
			map->coors[i][j].x = map->coors[i][j].x * map->step_xy;
			map->coors[i][j].y = map->coors[i][j].y * map->step_xy;
			map->coors[i][j].x += (glib->x / 2);
			map->coors[i][j].y += (glib->x / 2);
			map->coors[i][j].z = ft_atoi(row[j]);
			if (map->coors[i][j].z < map->lz)
				map->lz = map->coors[i][j].z;
			if (map->coors[i][j].z > map->hz)
				map->hz = map->coors[i][j].z;
			j++;
			// printf("%.1f %.1f\n", map->lz, map->hz);
		}
		ft_free_row(row, map->rl);
		i++;
	}
}

/**
 * @brief Allocate memory for map.coors and map.coors_tr.
 *
 * @param glib Data struct
 * @return int 1 on success, 0 if allocation fails.
 */
static int	ft_allocate_coors(t_glib *glib)
{
	t_map	*map;
	int		i;

	map = glib->map;
	i = 0;
	map->coors = (t_point **)ft_calloc(map->rc, sizeof (t_point *));
	map->coors_tr = (t_point **)ft_calloc(map->rc, sizeof (t_point *));
	if (map->coors == NULL || map->coors_tr == NULL)
		return (0);
	while (i < map->rc)
	{
		map->coors[i] = (t_point *)ft_calloc(map->rl, sizeof (t_point));
		map->coors_tr[i] = (t_point *)ft_calloc(map->rl, sizeof (t_point));
		if (map->coors[i] == NULL || map->coors_tr[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Free an array of arrays
 *
 * @param row char ** to be freed
 * @param l	number of char * in row
 */
static void	ft_free_row(char **row, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		free(row[i]);
		i++;
	}
	free(row);
}
