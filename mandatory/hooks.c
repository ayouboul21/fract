/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:42:14 by aoulahra          #+#    #+#             */
/*   Updated: 2024/03/04 21:17:08 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		destroy_window(mlx);
	return (0);
}

int	destroy_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

int	mouse_hook_m(int keycode, int mx, int my, t_mlx *mlx)
{
	unsigned int	*os;

	os = NULL;
	(void)mx;
	(void)my;
	if (keycode == 4)
	{
		mlx->c->z /= 0.9;
		draw_mandelbrot(mlx, os);
	}
	else if (keycode == 5)
	{
		mlx->c->z *= 0.9;
		draw_mandelbrot(mlx, os);
	}
	return (0);
}

int	mouse_hook_j(int keycode, int mx, int my, t_mlx *mlx)
{
	unsigned int	*os;

	os = NULL;
	(void)mx;
	(void)my;
	if (keycode == 4)
	{
		mlx->c->z /= 0.9;
		draw_julia(mlx, os, mlx->cmp);
	}
	else if (keycode == 5)
	{
		mlx->c->z *= 0.9;
		draw_julia(mlx, os, mlx->cmp);
	}
	return (0);
}
