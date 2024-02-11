/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:12:46 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/19 12:02:47 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_gnl(char *buffer, size_t start, size_t end, int if_free)
{
	size_t	i;
	char	*pol_line;

	if (!buffer)
		return (NULL);
	i = -1;
	pol_line = (char *)malloc(end - start + 1);
	if (!pol_line)
	{
		if (if_free)
			free(buffer);
		return (NULL);
	}
	while (++i < end - start)
		pol_line[i] = buffer[start + i];
	pol_line[i] = '\0';
	if (if_free)
		free(buffer);
	return (pol_line);
}

char	*ft_get_line(int fd, int *fn)
{
	size_t	bytes;
	char	*next_line;
	char	*tmp_buffer;

	next_line = (char *)malloc(1);
	if (!next_line)
		return (*fn = -1, NULL);
	tmp_buffer = (char *)malloc(((size_t)BUFFER_SIZE + 1));
	if (!tmp_buffer)
		return (*fn = -1, next_line = ft_freeit(next_line, NULL));
	next_line[0] = '\0';
	while (!(*fn))
	{
		bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		tmp_buffer[bytes] = '\0';
		next_line = ft_strjoin_gnl(next_line, tmp_buffer, fn, 1);
		if (!next_line)
			return (next_line = ft_freeit(tmp_buffer, NULL));
	}
	free(tmp_buffer);
	if (bytes < 0 || (next_line && !bytes && !*next_line))
		return (next_line = ft_freeit(next_line, NULL));
	return (next_line);
}

char	*get_next_line(int fd)
{
	int			fn;
	char		*line;
	char		*tmp_buffer;
	static char	*buffer;

	fn = 0;
	if (fd < 0 || BUFFER_SIZE > INT_MAX
		|| BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (buffer = ft_freeit(buffer, NULL));
	if (!buffer)
		buffer = ft_calloc_gnl(1);
	line = ft_get_line(fd, &fn);
	if (!line && ((buffer && buffer[0] == '\0') || fn == -1))
		return (buffer = ft_freeit(buffer, NULL));
	tmp_buffer = ft_strjoin_gnl(buffer, line, &fn, 2);
	if (!tmp_buffer)
		return (buffer = ft_freeit(NULL, line));
	line = ft_substr_gnl(tmp_buffer, 0, ft_strlen_n(tmp_buffer, &fn, 1), 0);
	if (!line)
		return (buffer = ft_freeit(tmp_buffer, NULL));
	buffer = ft_substr_gnl(tmp_buffer, ft_strlen_n(tmp_buffer, &fn, 1),
			ft_strlen_n(tmp_buffer, &fn, 0), 1);
	if (!buffer)
		return (line = ft_freeit(line, NULL));
	return (line);
}
