/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:57:21 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/11 12:48:23 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	f(void)
{
	system("leaks fractol");
}
void	init_cords(t_mlx *mlx)
{
	mlx->cords = NULL;
	mlx->cords = (t_coords *)malloc(sizeof(t_coords));
	if (!mlx->cords)
		exit(EXIT_FAILURE);
	mlx->cords->x = 2;
	mlx->cords->y = 2;
	mlx->cords->width = 800;
	mlx->cords->height = 800;
}
int	main(void)
{
	unsigned int	*os;
	t_mlx			*mlx;

	atexit(f);
	os = NULL;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit (1);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit (0);
	init_cords(mlx);
	mlx->win = mlx_new_window(mlx->mlx, mlx->cords->width,
				mlx->cords->height, "Mandelbrot");
	mlx->img = mlx_new_image(mlx->mlx, mlx->cords->width, mlx->cords->height);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->size_line, &mlx->endian);
	draw_mandelbrot(mlx, os);
	mlx_key_hook(mlx->win, key_press_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 17, 0, &destroy_window, mlx);
	mlx_loop(mlx->mlx);
	free(mlx);
	exit (0);
}
