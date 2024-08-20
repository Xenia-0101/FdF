/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:53:06 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 15:19:25 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_colour(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void print_rgba(int rgba)
{
	int r = (rgba >> 24) & 0xFF;
	int g = (rgba >> 16) & 0xFF;
	int b = (rgba >> 8) & 0xFF;
	int a = (rgba) & 0xFF;
	printf("%d | %d | %d | %d \n", r, g, b, a);
	printf("%x\n", ft_get_colour(r, g, b, a));
}

void	ft_put_point(t_glib *glib, int p[2])
{
	int	c;

	c = ft_get_colour(255, 166, 75, 255);
	if ((p[0] > 10 && p[1] > 10) && !(p[0] > (glib->x - 10) || p[1] > (glib->y - 10)))
		mlx_put_pixel(glib->img, p[0], p[1], c);
}

void	ft_reset_img(t_glib *glib)
{
	memset(glib->img->pixels, 0xFF, glib->img->width * glib->img->height * sizeof (int32_t));
}

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
