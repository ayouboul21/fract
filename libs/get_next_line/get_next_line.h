/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:16:27 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/19 10:15:14 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include "stdlib.h"
# include "unistd.h"
# include "limits.h"

char	*get_next_line(int fd);
void	*ft_freeit(char *line, char *buffer);
char	*ft_calloc_gnl(size_t size);
size_t	ft_strlen_n(char *str, int *found_n, int mode);
char	*ft_strjoin_gnl(char *line, char *buffer, int *fn, int who_to_free);
void	ft_shift_buffer(char *buffer);

#endif