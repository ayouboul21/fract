/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:54:51 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/24 08:25:28 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_c(t_mlx *mlx)
{
	mlx->c = NULL;
	mlx->c = (t_coords *)malloc(sizeof(t_coords));
	if (!mlx->c)
		exit(EXIT_FAILURE);
	mlx->c->x = 2;
	mlx->c->y = 2;
	mlx->c->width = 800;
	mlx->c->height = 800;
	mlx->c->z = 1;
}

unsigned int	choose_color(unsigned int iter, int r_m, int g_m, int b_m)
{
	int	red;
	int	green;
	int	blue;

	red = (iter * r_m) % 256;
	green = (iter * g_m) % 256;
	blue = (iter * b_m) % 256;
	return ((red << 16) | (green << 8) | blue);
}
