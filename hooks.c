/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:42:14 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/11 12:49:26 by aoulahra         ###   ########.fr       */
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

int	mouse_hook(int keycode, t_mlx *mlx)
{
	unsigned int	*os;
	(void)mlx;

	os = NULL;
	ft_printf("%d\n", mlx->bpp);
	if (keycode == 4)
	{
		ft_printf("%d\n", keycode);
		mlx->cords->x -= 0.05;
		mlx->cords->y -= 0.05;
		draw_mandelbrot(mlx, os);
	}
	return (0);
}
