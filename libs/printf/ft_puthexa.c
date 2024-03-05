/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:20:49 by aoulahra          #+#    #+#             */
/*   Updated: 2024/03/04 21:16:47 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned long nb, char *base, int *counter)
{
	if (nb >= 16)
		ft_puthexa(nb / 16, base, counter);
	*counter += ft_putchar(base[nb % 16]);
}
