/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:54:51 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/24 16:08:06 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	init_c(t_mlx *mlx)
{
	mlx->c = NULL;
	mlx->c = (t_coords *)malloc(sizeof(t_coords));
	if (!mlx->c)
	{
		free(mlx);
		exit(EXIT_FAILURE);
	}
	re_init_c(mlx);
	return (1);
}

int	re_init_c(t_mlx *mlx)
{
	mlx->c->x_max = 2;
	mlx->c->x_min = -2;
	mlx->c->y_max = 2;
	mlx->c->y_min = -2;
	mlx->c->w = 800;
	mlx->c->h = 800;
	mlx->c->z = 1;
	mlx->c->iter = 0;
	mlx->clrs.blue = 9;
	mlx->clrs.green = 12;
	mlx->clrs.red = 2;
	return (1);
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

int	change_color(t_mlx *mlx)
{
	int	red;
	int	green;
	int	blue;

	red = mlx->clrs.red;
	green = mlx->clrs.green;
	blue = mlx->clrs.blue;
	mlx->clrs.red = green * 2;
	mlx->clrs.green = blue * 2;
	mlx->clrs.blue = red * 2;
	(mlx->clrs.blue % 256 == 0) && (mlx->clrs.blue = 9);
	(mlx->clrs.red % 256 == 0) && (mlx->clrs.red = 2);
	(mlx->clrs.green % 256 == 0) && (mlx->clrs.green = 12);
	return (1);
}
