/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:08:17 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/18 07:42:42 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static void		julia(t_mlx *mlx, int x, int y)
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
		mlx->nr = mlx->or * mlx->or - mlx->oi * mlx->oi + 0.3;
		mlx->ni = 2 * mlx->or * mlx->oi + 0.5;
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
	double	tmp1;
	double	tmp2;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		tmp1 = mlx->y_max - mlx->y_min;
		mlx->zi = ((double)y / W_HEIGHT) * tmp1 + mlx->y_min;
		while (x < W_WIDTH)
		{
			tmp2 = mlx->x_max - mlx->x_min;
			mlx->zr = ((double)x / W_WIDTH) * tmp2 + mlx->x_min;
			if (mlx->fractal == 0)
				mandelbrot(mlx, x, y);
			else if (mlx->fractal == 1)
				julia(mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
