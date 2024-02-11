/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:45:30 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/11 12:46:09 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double x, double y, int max_iter)
{
	int		i;
	double	re;
	double	im;
	double	re_tmp;

	re = 0;
	im = 0;
	i = 0;
	while (i < max_iter && re * re + im * im < 4)
	{
		re_tmp = re * re - im * im + x;
		im = 2 * re * im + y;
		re = re_tmp;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_mlx *mlx, unsigned int *os)
{
	int				x;
	int				y;
	int				iter_max;
	unsigned int	color;

	iter_max = 250;
	x = 0;
	while (x < mlx->cords->width)
	{
		y = 0;
		while (y < mlx->cords->height)
		{
			os = (unsigned int *)(mlx->data + y * mlx->size_line
					+ x * (mlx->bpp / 8));
			color = mandelbrot((double)x / mlx->cords->width * 2 * mlx->cords->x - mlx->cords->x,
					(double)y / mlx->cords->height * 2 * mlx->cords->y - mlx->cords->y, iter_max);
			*os = color * 0xff1ffff;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
