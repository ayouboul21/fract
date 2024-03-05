/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:45:30 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/24 08:29:57 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mandelbrot(double x, double y, int max_iter)
{
	int		i;
	double	re;
	double	im;
	double	re_tmp;

	re = 0;
	im = 0;
	i = 0;
	while (i < max_iter && re * re + im * im <= 4)
	{
		re_tmp = re * re - im * im + x;
		im = 2 * re * im + y;
		re = re_tmp;
		i++;
	}
	return (i);
}

int	draw_mandelbrot(t_mlx *mlx, unsigned int *os)
{
	int				x;
	int				y;
	unsigned int	iter_max;
	unsigned int	color;

	(1 == 1) && (iter_max = 50 + mlx->c->iter, x = 0);
	while (x < mlx->c->w)
	{
		y = 0;
		while (y < mlx->c->h)
		{
			os = (unsigned int *)(mlx->data + y * mlx->sl + x * (mlx->bpp / 8));
			color = mandelbrot(((double)x / mlx->c->w) * (mlx->c->x_max
						- mlx->c->x_min) + mlx->c->x_min, -((double)y
						/ mlx->c->h) * (mlx->c->y_max - mlx->c->y_min)
					- mlx->c->y_min, iter_max);
			(color == iter_max) && (*os = 0);
			(color != iter_max) && (*os = choose_color(color, mlx->clrs.red,
				mlx->clrs.green, mlx->clrs.blue));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

int	handle_mandelbrot(void)
{
	unsigned int	*os;
	t_mlx			*mlx;

	os = NULL;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit (1);
	mlx->mlx = mlx_init();
	init_c(mlx);
	mlx->win = mlx_new_window(mlx->mlx, mlx->c->w,
			mlx->c->h, "Mandelbrot");
	ft_check_wind(mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, mlx->c->w, mlx->c->h);
	ft_check_img(mlx);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->sl, &mlx->endian);
	draw_mandelbrot(mlx, os);
	mlx_hook(mlx->win, 2, 0, key_press_hook_m, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook_m, mlx);
	mlx_hook(mlx->win, 17, 0, &destroy_window, mlx);
	mlx_loop(mlx->mlx);
	free(mlx);
	exit (0);
}
