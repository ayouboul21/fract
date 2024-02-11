/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:07:42 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/19 12:20:59 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	char	*joint;

	if (!s1 || !s2)
		return (NULL);
	(1 == 1) && (size1 = ft_strlen(s1), size2 = ft_strlen(s2));
	i = 0;
	joint = (char *) malloc (sizeof(char ) * (size1 + size2 + 1));
	if (!joint)
		return (NULL);
	while (i < size1)
	{
		joint[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		joint[i] = s2[i - size1];
		i++;
	}
	joint[i] = '\0';
	free(s1);
	return (joint);
}
