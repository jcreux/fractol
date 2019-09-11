/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:08:17 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/11 20:30:29 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static void		julia(t_mlx *mlx, int x, int y)
{
	mlx->i = 0;
	mlx->new_r = 0;
	mlx->new_i = 0;
	mlx->old_r = 0;
	mlx->old_i = 0;
	while ((mlx->new_r * mlx->new_r + mlx->new_i * mlx->new_i) < 4 && mlx->i < mlx->iter)
	{
		mlx->old_r = mlx->new_r;
		mlx->old_i = mlx->new_i;
		mlx->new_r = mlx->old_r * mlx->old_r - mlx->old_i * mlx->old_i + 0.3;
		mlx->new_i = 2 * mlx->old_r * mlx->old_i + 0.5;
		mlx->i++;
	}
	color(mlx, x, y);
}

static void		mandelbrot(t_mlx *mlx, int x, int y)
{
	mlx->i = 0;
	mlx->new_r = 0;
	mlx->new_i = 0;
	mlx->old_r = 0;
	mlx->old_i = 0;
	while ((mlx->new_r * mlx->new_r + mlx->new_i * mlx->new_i) < 4 && mlx->i < mlx->iter)
	{
		mlx->old_r = mlx->new_r;
		mlx->old_i = mlx->new_i;
		mlx->new_r = mlx->old_r * mlx->old_r - mlx->old_i * mlx->old_i + mlx->z_r;
		mlx->new_i = 2 * mlx->old_r * mlx->old_i + mlx->z_i;
		mlx->i++;
	}
	color(mlx, x, y);
}

void			create_fractal(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		mlx->z_i = ((double)y / WIN_HEIGHT) * (mlx->y_max - mlx->y_min) + mlx->y_min;
		while (x < WIN_WIDTH)
		{
			mlx->z_r = ((double)x / WIN_WIDTH) * (mlx->x_max - mlx->x_min) + mlx->x_min;
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
