/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:08:17 by jcreux            #+#    #+#             */
/*   Updated: 2019/08/20 23:38:57 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static void		fill_pixel(t_mlx *mlx, int x, int y, unsigned int color)
{
	t_rgb	rgb;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		rgb.red = color / (CHAR_RANGE * CHAR_RANGE);
		rgb.green = (color / CHAR_RANGE) % CHAR_RANGE;
		rgb.blue = color % CHAR_RANGE;
		mlx->img_data[x * 4 + y * 4 * WIN_WIDTH] = rgb.blue;
		mlx->img_data[x * 4 + y * 4 * WIN_WIDTH + 1] = rgb.green;
		mlx->img_data[x * 4 + y * 4 * WIN_WIDTH + 2] = rgb.red;
		mlx->img_data[x * 4 + y * 4 * WIN_WIDTH + 3] = 0;
	}
}

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
	if (mlx->i == mlx->iter)
		fill_pixel(mlx, x, y, 0xffffff);
	else
		fill_pixel(mlx, x, y, 0);
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
	if (mlx->i == mlx->iter)
		fill_pixel(mlx, x, y, 0xffffff);
	else
		fill_pixel(mlx, x, y, 0);
}

void			create_fractal(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	mlx->iter = 50;
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
