/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:22:05 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/25 14:44:43 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"

typedef struct s_coords
{
	int		height;
	int		width;
	double	x;
	double	y;
	double	z;
}	t_coords;
typedef struct s_cmplex
{
	double	re;
	double	im;
}	t_cmplex;
typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	t_coords	*c;
	t_cmplex	cmp;
}	t_mlx;

int				destroy_window(t_mlx *mlx);
void			ft_check_wind(void *win);
void			ft_check_img(t_mlx *mlx);
int				mouse_hook_j(int keycode, int mx, int my, t_mlx *mlx);
int				mouse_hook_m(int keycode, int mx, int my, t_mlx *mlx);
int				key_press_hook(int keycode, t_mlx *mlx);
int				handle_mandelbrot(void);
int				handle_julia(char *real, char *imagin);
void			draw_mandelbrot(t_mlx *mlx, unsigned int *os);
void			draw_julia(t_mlx *mlx, unsigned int *os, t_cmplex c);
t_cmplex		init_cmplex(char *real, char *imagin);
void			init_c(t_mlx *mlx);
unsigned int	choose_color(unsigned int iter, int r_m, int g_m, int b_m);

#endif