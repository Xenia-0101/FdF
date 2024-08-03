/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:24:30 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/22 17:44:14 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(int count, int size)
{
	int		res;
	char	*ptr;

	if (count == 0 || size == 0)
	{
		return (NULL);
	}
	res = count * size;
	if (res < count || res < size)
	{
		return (NULL);
	}
	ptr = (char *)malloc(res);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (res > 0)
	{
		res--;
		ptr[res] = '\0';
	}
	return (ptr);
}

int	has_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (0);
	}
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str3;

	i = ft_strlen(str1);
	j = ft_strlen(str2);
	str3 = ft_calloc((i + j + 1), sizeof (char));
	if (str3 == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str1 && str1[i])
	{
		str3[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		str3[i + j] = str2[j];
		j++;
	}
	free(str1);
	return (str3);
}
