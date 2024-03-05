/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:45:30 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/24 08:19:42 by aoulahra         ###   ########.fr       */
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
	while (i < max_iter && re * re + im * im <= 4)
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
	unsigned int	iter_max;
	unsigned int	color;

	(1 == 1) && (iter_max = 30, x = 0);
	while (x < mlx->c->width)
	{
		y = 0;
		while (y < mlx->c->height)
		{
			os = (unsigned int *)(mlx->data + y * mlx->sl + x * (mlx->bpp / 8));
			color = mandelbrot((mlx->c->x / mlx->c->z) * ((double)x
						/ mlx->c->width * 2 - 1), (mlx->c->y / mlx->c->z)
					* (-(double)y / mlx->c->height * 2 + 1), iter_max);
			(color == iter_max) && (*os = 0);
			(color != iter_max) && (*os = choose_color(color, 2, 12, 9));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
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
	if (!mlx->mlx)
		exit (0);
	init_c(mlx);
	mlx->win = mlx_new_window(mlx->mlx, mlx->c->width,
			mlx->c->height, "Mandelbrot");
	ft_check_wind(mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, mlx->c->width, mlx->c->height);
	ft_check_img(mlx);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->endian);
	draw_mandelbrot(mlx, os);
	mlx_key_hook(mlx->win, key_press_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook_m, mlx);
	mlx_hook(mlx->win, 17, 0, &destroy_window, mlx);
	mlx_loop(mlx->mlx);
	free(mlx);
	exit (0);
}
