/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:08:49 by xvislock          #+#    #+#             */
/*   Updated: 2024/10/09 16:12:00 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_write_msg(void)
{
	write(1, "\
\n\
\033[0;32mThis project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.\033[0m \n\
\n\
Things to try: \n\
\n\
\033[0;33mleft\033[0m   | move left \n\
\033[0;33mright\033[0m  | move right \n\
\033[0;33mup\033[0m     | move up \n\
\033[0;33mdown\033[0m   | move down \n\
\033[0;33mz\033[0m      | stretch \n\
\033[0;33mx\033[0m      | shrink \n\
\033[0;33m+\033[0m      | zoom in \n\
\033[0;33m-\033[0m      | zoom out \n\
\033[0;33ma, d\033[0m   | rotate around x axis \n\
\033[0;33mw, s\033[0m   | rotate around y axis \n\
\033[0;33mq, e\033[0m   | rotate around x = y axis \n\
\033[0;33m1\033[0m      | toggle projection isometric / oblique \n\
\033[0;33m7, 8\033[0m   | oblique projection parameters \n\
\033[0;33m4, 5\033[0m   | oblique projection parameters \n\
\033[0;33mesc\033[0m    | exit programme \n\
", 704);
}