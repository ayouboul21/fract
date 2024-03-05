/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:22:05 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/24 16:08:26 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include "mlx.h"
# include "math.h"
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"

typedef struct s_colors
{
	int		blue;
	int		red;
	int		green;
}	t_colors;
typedef struct s_coords
{
	int		h;
	int		w;
	int		iter;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	double	z;
}	t_coords;
typedef struct s_cmplex
{
	double	x;
	double	y;
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
	t_colors	clrs;
}	t_mlx;

int				destroy_window(t_mlx *mlx);
void			ft_check_wind(void *win);
void			ft_check_img(t_mlx *mlx);
int				mouse_hook_j(int keycode, int mx, int my, t_mlx *mlx);
int				mouse_hook_m(int keycode, int mx, int my, t_mlx *mlx);
int				mouse_hook_b(int key, int mx, int my, t_mlx *mlx);
int				key_press_hook_m(int keycode, t_mlx *mlx);
int				key_press_hook_j(int keycode, t_mlx *mlx);
int				key_press_hook_b(int key, t_mlx *mlx);
int				handle_mandelbrot(void);
int				handle_ship(void);
int				handle_julia(char *real, char *imagin);
int				draw_mandelbrot(t_mlx *mlx, unsigned int *os);
int				draw_julia(t_mlx *mlx, unsigned int *os, t_cmplex c);
int				draw_burning_ship(t_mlx *mlx, unsigned int *os);
t_cmplex		init_cmplex(char *real, char *imagin);
int				init_c(t_mlx *mlx);
int				re_init_c(t_mlx *mlx);
void			ft_scale(t_mlx *mlx);
double			ft_range(t_mlx *mlx, double add, char c);
int				change_color(t_mlx *mlx);
unsigned int	choose_color(unsigned int iter, int r_m, int g_m, int b_m);

#endif