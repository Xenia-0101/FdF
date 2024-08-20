/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:32:56 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/20 12:04:51 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	ft_sgn(int i)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
		return (1);
	return (0);
}

float	ft_rad(int i)
{
	return (i * 3.14 / 180);
}
