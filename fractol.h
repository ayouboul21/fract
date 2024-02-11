/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:22:05 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/11 12:44:21 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libs/libft/libft.h"
# include "libs/printf/ft_printf.h"
# include "libs/get_next_line/get_next_line.h"

typedef struct s_coords
{
	int		height;
	int		width;
	double	x;
	double	y;
}	t_coords;
typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_coords	*cords;
}	t_mlx;

int		destroy_window(t_mlx *mlx);
int		mouse_hook(int keycode, t_mlx *mlx);
int		key_press_hook(int keycode, t_mlx *mlx);
void	draw_mandelbrot(t_mlx *mlx, unsigned int *os);

#endif