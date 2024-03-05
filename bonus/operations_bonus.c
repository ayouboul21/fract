/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:04:49 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/19 19:07:42 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

	if (!str)
		return (0);
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

	c.x = 0;
	c.y = 0;
	c.re = atodouble(real);
	c.im = atodouble(imagin);
	return (c);
}

void	ft_scale(t_mlx *mlx)
{
	mlx->c->x_max = mlx->cmp.x + mlx->c->z * (mlx->c->x_max - mlx->cmp.x);
	mlx->c->x_min = mlx->cmp.x + mlx->c->z * (mlx->c->x_min - mlx->cmp.x);
	mlx->c->y_max = mlx->cmp.y + mlx->c->z * (mlx->c->y_max - mlx->cmp.y);
	mlx->c->y_min = mlx->cmp.y + mlx->c->z * (mlx->c->y_min - mlx->cmp.y);
}

double	ft_range(t_mlx *mlx, double add, char c)
{
	if (c == 'x')
		return ((mlx->c->x_max - mlx->c->x_min) * add / (double)4);
	if (c == 'y')
		return ((mlx->c->y_max - mlx->c->y_min) * add / (double)4);
	return (0);
}
