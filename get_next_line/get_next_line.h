/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:18:01 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/22 12:18:01 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
int		has_newline(char *str);
char	*ft_calloc(int count, int size);
char	*get_next_line(int fd);
char	*move_next(char *src);
char	*get_line(char *cont);
char	*read_fd(int fd, char *cont);

#endif
