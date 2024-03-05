/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:04:49 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/24 22:28:50 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	neg_pow(int n, int pow)
{
	double	res;

	res = 1;
	while (pow)
	{
		res *= 1 / (double)n;
		pow--;
	}
	return (res);
}

double	atodouble(char *str)
{
	int		i;
	int		sign;
	double	res;

	(1 == 1) && (res = 0, sign = 1, i = 1);
	(*str == '-') && (str++, sign = -1);
	(*str == '+' && sign == 1) && (str++);
	while (*str <= '9' && *str >= '0')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str <= '9' && *str >= '0')
		{
			(*str == '0') && (i++);
			(*str != '0') && (res += neg_pow(10, i) * (*str - '0'), i++);
			str++;
		}
	}
	return (res * (double)sign);
}

t_cmplex	init_cmplex(char *real, char *imagin)
{
	t_cmplex	c;

	c.re = atodouble(real);
	c.im = atodouble(imagin);
	return (c);
}

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
