/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:08:17 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/26 13:07:57 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static double	ft_abs2(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void		third(t_mlx *mlx, int x, int y)
{
	mlx->i = 0;
	mlx->nr = 0;
	mlx->ni = 0;
	mlx->or = 0;
	mlx->oi = 0;
	while ((mlx->nr * mlx->nr + mlx->ni * mlx->ni) < 4 && mlx->i < mlx->iter)
	{
		mlx->or = ft_abs2(mlx->nr);
		mlx->oi = ft_abs2(mlx->ni);
		mlx->nr = mlx->or * mlx->or - mlx->oi * mlx->oi + mlx->zr;
		mlx->ni = 2 * mlx->or * mlx->oi + mlx->zi;
		mlx->i++;
	}
	color(mlx, x, y);
}

static void		julia(t_mlx *mlx, int x, int y)
{
	double	tmp;

	mlx->i = 0;
	mlx->nr = mlx->zr;
	mlx->ni = mlx->zi;
	while ((mlx->nr * mlx->nr + mlx->ni * mlx->ni) < 4 && mlx->i < mlx->iter)
	{
		tmp = mlx->nr * mlx->nr - mlx->ni * mlx->ni + mlx->re;
		mlx->ni = 2 * mlx->nr * mlx->ni + mlx->im;
		mlx->nr = tmp;
		mlx->i++;
	}
	color(mlx, x, y);
}

static void		mandelbrot(t_mlx *mlx, int x, int y)
{
	mlx->i = 0;
	mlx->nr = 0;
	mlx->ni = 0;
	mlx->or = 0;
	mlx->oi = 0;
	while ((mlx->nr * mlx->nr + mlx->ni * mlx->ni) < 4 && mlx->i < mlx->iter)
	{
		mlx->or = mlx->nr;
		mlx->oi = mlx->ni;
		mlx->nr = mlx->or * mlx->or - mlx->oi * mlx->oi + mlx->zr;
		mlx->ni = 2 * mlx->or * mlx->oi + mlx->zi;
		mlx->i++;
	}
	color(mlx, x, y);
}

void			create_fractal(t_mlx *mlx)
{
	int		x;
	int		y;
	double	tmp;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		tmp = mlx->y_max - mlx->y_min;
		mlx->zi = ((double)y / W_HEIGHT) * tmp + mlx->y_min;
		while (x < W_WIDTH)
		{
			tmp = mlx->x_max - mlx->x_min;
			mlx->zr = ((double)x / W_WIDTH) * tmp + mlx->x_min;
			if (mlx->fractal == 0)
				mandelbrot(mlx, x, y);
			else if (mlx->fractal == 1)
				julia(mlx, x, y);
			else if (mlx->fractal == 2)
				third(mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
