/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:42:48 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/25 14:32:14 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

unsigned int	burning_ship(double x, double y, int max_iter, int i)
{
	double	zx;
	double	zy;
	double	zx2;
	double	zy2;
	double	tmp;

	zx = 0;
	zy = 0;
	zx2 = 0;
	zy2 = 0;
	while (i < max_iter && zx2 + zy2 <= 4)
	{
		tmp = zx2 - zy2 + x;
		zy = fabs(2 * zx * zy) + y;
		zx = tmp;
		zx2 = zx * zx;
		zy2 = zy * zy;
		i++;
	}
	return (i);
}

int	draw_burning_ship(t_mlx *mlx, unsigned int *os)
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
			color = burning_ship(((double)x / mlx->c->w) * (mlx->c->x_max
						- mlx->c->x_min) + mlx->c->x_min, ((double)y
						/ mlx->c->h) * (mlx->c->y_max - mlx->c->y_min)
					+ mlx->c->y_min, iter_max, 0);
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

int	handle_ship(void)
{
	unsigned int	*os;
	t_mlx			*mlx;

	os = NULL;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit (EXIT_FAILURE);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit (0);
	init_c(mlx);
	mlx->win = mlx_new_window(mlx->mlx, mlx->c->w, mlx->c->h, "Burning Ship");
	ft_check_wind(mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, mlx->c->w, mlx->c->h);
	ft_check_img(mlx);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->endian);
	draw_burning_ship(mlx, os);
	mlx_hook(mlx->win, 2, 0, key_press_hook_b, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook_b, mlx);
	mlx_hook(mlx->win, 17, 0, &destroy_window, mlx);
	mlx_loop(mlx->mlx);
	free(mlx);
	exit (EXIT_SUCCESS);
}
