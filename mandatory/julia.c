/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:41:55 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/24 08:21:37 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	julia(double x, double y, t_cmplex c, int max_iter)
{
	int		i;
	double	re;
	double	im;
	double	re_tmp;

	re = x;
	im = y;
	i = 0;
	while (i < max_iter && re * re + im * im <= 4)
	{
		re_tmp = re * re - im * im + c.re;
		im = 2 * re * im + c.im;
		re = re_tmp;
		i++;
	}
	return (i);
}

void	draw_julia(t_mlx *mlx, unsigned int *os, t_cmplex c)
{
	int				x;
	int				y;
	unsigned int	iter_max;
	unsigned int	color;

	(1 == 1) && (iter_max = 150, x = 0);
	while (x < mlx->c->width)
	{
		y = 0;
		while (y < mlx->c->height)
		{
			os = (unsigned int *)(mlx->data + y * mlx->sl + x * (mlx->bpp / 8));
			color = julia((mlx->c->x / mlx->c->z) * ((double)x
						/ mlx->c->width * 2 - 1), (mlx->c->y / mlx->c->z)
					* ((double)y / mlx->c->height * 2 - 1), c, iter_max);
			(color == iter_max) && (*os = 0);
			(color != iter_max) && (*os = choose_color(color, 2, 12, 9));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

int	handle_julia(char *real, char *imagin)
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
	mlx->cmp = init_cmplex(real, imagin);
	mlx->win = mlx_new_window(mlx->mlx, mlx->c->width, mlx->c->height, "Julia");
	ft_check_wind(mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, mlx->c->width, mlx->c->height);
	ft_check_img(mlx);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->endian);
	draw_julia(mlx, os, mlx->cmp);
	mlx_key_hook(mlx->win, key_press_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook_j, mlx);
	mlx_hook(mlx->win, 17, 0, &destroy_window, mlx);
	mlx_loop(mlx->mlx);
	free(mlx);
	exit (EXIT_SUCCESS);
}
