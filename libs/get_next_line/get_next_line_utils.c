/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:21:49 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/19 10:15:47 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_n(char *str, int *found_n, int mode)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (mode == 1)
	{
		while (str[i] && str[i] != '\n')
			i++;
		*found_n = (str[i] == '\n');
		i += *found_n;
	}
	else
	{
		while (str && str[i])
		{
			*found_n += (str[i] == '\n');
			i++;
		}
	}
	return (i);
}

void	*ft_freeit(char *line, char *buffer)
{
	if (line)
		free(line);
	if (buffer)
		free(buffer);
	return (NULL);
}

char	*ft_calloc_gnl(size_t size)
{
	char	*str;

	str = (char *)malloc(size);
	if (str)
	{
		while (size--)
			str[size] = 0;
	}
	return (str);
}

char	*ft_strjoin_gnl(char *line, char *buffer, int *fn, int who_to_free)
{
	char	*new_line;
	size_t	i;
	size_t	len;
	size_t	size;

	if (!line)
		return (NULL);
	i = -1;
	size = ft_strlen_n(line, fn, 0);
	len = ft_strlen_n(buffer, fn, 0);
	new_line = (char *)malloc(size + len + 1);
	if (!new_line)
		return (line = ft_freeit(line, NULL));
	while (++i < size)
		new_line[i] = line[i];
	i = -1;
	while (++i < len)
		new_line[i + size] = buffer[i];
	new_line[size + len] = '\0';
	if (who_to_free == 2)
		buffer = ft_freeit(buffer, NULL);
	line = ft_freeit(line, NULL);
	return (new_line);
}
