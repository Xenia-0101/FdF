/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:53:06 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/21 11:23:35 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_colour(int r, int g, int b, int a);
void	ft_put_point(t_glib *glib, int p[2]);
void	ft_reset_img(t_glib *glib);
int		ft_count_spaces(char *s);

/**
 * @brief Returns int representing color
 *
 * @param r	Amount of red
 * @param g	Amount of green
 * @param b	Amount of blue
 * @param a	Amount of alpha
 * @return int
 */
int	ft_get_colour(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/**
 * @brief Draws a point on the image
 *
 * @param glib	Data struct
 * @param p		Point x and y coors
 */
void	ft_put_point(t_glib *glib, int p[2])
{
	int	c;

	c = ft_get_colour(0, 0, 255, 255);
	if ((p[0] > 10 && p[1] > 10)
		&& !(p[0] > (glib->x - 10) || p[1] > (glib->y - 10)))
		mlx_put_pixel(glib->img, p[0], p[1], c);
}

/**
 * @brief Reset image pixels to black
 *
 * @param glib Data struct
 */
void	ft_reset_img(t_glib *glib)
{
	size_t	s;
	int		c;

	s = glib->img->width * glib->img->height * sizeof (int32_t);
	c = ft_get_colour(0, 0, 0, 255);
	memset(glib->img->pixels, c, s);
}

/**
 * @brief Gets the number of points in a row of a map.
 *
 * By counting spaces deliminating points in the map file.
 *
 * @param s		string
 * @return int	count of points
 */
int	ft_count_spaces(char *s)
{
	int		i;
	char	**srow;

	srow = ft_split(s, ' ');
	i = 0;
	while (srow[i] && (srow[i][0] == '-' || ft_isdigit(srow[i][0])))
	{
		free(srow[i]);
		i++;
	}
	if (srow[i])
		free(srow[i]);
	free(srow);
	return (i);
}
