/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:52:40 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/25 14:34:31 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_press_hook_b(int key, t_mlx *mlx)
{
	unsigned int	*os;

	os = NULL;
	(key == 82) && (re_init_c(mlx)) && (draw_burning_ship(mlx, os));
	(key == 53) && (destroy_window(mlx));
	(key == 126) && (mlx->c->y_max -= ft_range(mlx, 0.1, 'y'),
	mlx->c->y_min -= ft_range(mlx, 0.1, 'y')) &&
		(draw_burning_ship(mlx, os));
	(key == 125) && (mlx->c->y_max += ft_range(mlx, 0.1, 'y'),
	mlx->c->y_min += ft_range(mlx, 0.1, 'y')) &&
		(draw_burning_ship(mlx, os));
	(key == 124) && (mlx->c->x_max += ft_range(mlx, 0.1, 'x'),
	mlx->c->x_min += ft_range(mlx, 0.1, 'x')) &&
		(draw_burning_ship(mlx, os));
	(key == 123) && (mlx->c->x_max -= ft_range(mlx, 0.1, 'x'),
	mlx->c->x_min -= ft_range(mlx, 0.1, 'x')) &&
		(draw_burning_ship(mlx, os));
	(key == 49) && (change_color(mlx) && draw_burning_ship(mlx, os));
	return (0);
}

int	mouse_hook_b(int key, int mx, int my, t_mlx *mlx)
{
	unsigned int	*os;

	os = NULL;
	mlx->cmp.x = ((double)mx / mlx->c->w) * (mlx->c->x_max
			- mlx->c->x_min) + mlx->c->x_min;
	mlx->cmp.y = ((double)my / mlx->c->h) * (mlx->c->y_max
			- mlx->c->y_min) + mlx->c->y_min;
	if (key == 4)
	{
		mlx->c->iter += 1;
		mlx->c->z = 0.8;
		ft_scale(mlx);
		draw_burning_ship(mlx, os);
	}
	else if (key == 5)
	{
		(mlx->c->iter > 0) && (mlx->c->iter -= 1);
		mlx->c->z = 1.2;
		ft_scale(mlx);
		draw_burning_ship(mlx, os);
	}
	return (0);
}
