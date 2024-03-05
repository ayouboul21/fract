/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:57:21 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/25 14:35:35 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_check_wind(void *win)
{
	if (!win)
		exit(EXIT_FAILURE);
}

void	ft_check_img(t_mlx *mlx)
{
	if (!mlx->img)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_FAILURE);
	}
}

void	print_options(void)
{
	ft_printf("Your options are:\n");
	ft_printf("+ Mandelbrot to execute type 'mandelbrot' as an argument\n");
	ft_printf("+ Burning Ship to execute type 'burning ship' as an argument\n");
	ft_printf("+ Julia to execute type 'julia'");
	ft_printf(" as an argument then the value of c\n");
	ft_printf("for the value of C you have to give 2 arguments the real");
	ft_printf(" part as first argument then imaginary part\n\n");
	ft_printf("./fractol_bonus mandelbrot\nor\n");
	ft_printf("./fractol_bonus julia real imaginary\nor\n");
	ft_printf("./fractol_bonus 'burning ship'\n");
	exit(EXIT_FAILURE);
}

int	check_arguments(char *str)
{
	int		sign;

	(1 == 1) && (sign = 1);
	(*str == '-') && (str++, sign = -1);
	(*str == '+' && sign == 1) && (str++);
	if (!*str || *str == '.')
		return (0);
	while (*str <= '9' && *str >= '0')
		str++;
	if (*str == '.')
	{
		str++;
		if (!*str)
			return (0);
		while (*str <= '9' && *str >= '0')
			str++;
	}
	if (*str)
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		handle_mandelbrot();
	else if ((ac == 4) && !ft_strncmp(av[1], "julia", 6))
	{
		if (!check_arguments(av[2]) || !check_arguments(av[3]))
		{
			ft_printf("Error non numerucal arguments\n");
			print_options();
		}
		handle_julia(av[2], av[3]);
	}
	else if (ac == 2 && !ft_strncmp(av[1], "burning ship", 13))
		handle_ship();
	else
		print_options();
}
