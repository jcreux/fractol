/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:07:46 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/26 14:04:11 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_pixel(t_mlx *mlx, int x, int y, unsigned int color)
{
	t_rgb	rgb;

	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		rgb.red = color / (CHAR_RANGE * CHAR_RANGE);
		rgb.green = (color / CHAR_RANGE) % CHAR_RANGE;
		rgb.blue = color % CHAR_RANGE;
		mlx->img_data[x * 4 + y * 4 * W_WIDTH] = rgb.blue;
		mlx->img_data[x * 4 + y * 4 * W_WIDTH + 1] = rgb.green;
		mlx->img_data[x * 4 + y * 4 * W_WIDTH + 2] = rgb.red;
		mlx->img_data[x * 4 + y * 4 * W_WIDTH + 3] = 0;
	}
}

static void	first_set(t_mlx *mlx, int x, int y)
{
	if (mlx->i % 10 == 0)
		fill_pixel(mlx, x, y, 0x000000);
	else if (mlx->i % 10 == 1)
		fill_pixel(mlx, x, y, 0x0a0d17);
	else if (mlx->i % 10 == 2)
		fill_pixel(mlx, x, y, 0x151a2e);
	else if (mlx->i % 10 == 3)
		fill_pixel(mlx, x, y, 0x202745);
	else if (mlx->i % 10 == 4)
		fill_pixel(mlx, x, y, 0x2a355d);
	else if (mlx->i % 10 == 5)
		fill_pixel(mlx, x, y, 0x8466a3);
	else if (mlx->i % 10 == 6)
		fill_pixel(mlx, x, y, 0x704c93);
	else if (mlx->i % 10 == 7)
		fill_pixel(mlx, x, y, 0x5b3284);
	else if (mlx->i % 10 == 8)
		fill_pixel(mlx, x, y, 0x471975);
	else if (mlx->i % 10 == 9)
		fill_pixel(mlx, x, y, 0x330066);
}

static void	second_set(t_mlx *mlx, int x, int y)
{
	if (mlx->i % 10 == 0)
		fill_pixel(mlx, x, y, 0x000000);
	else if (mlx->i % 10 == 1)
		fill_pixel(mlx, x, y, 0xe59400);
	else if (mlx->i % 10 == 2)
		fill_pixel(mlx, x, y, 0xffa500);
	else if (mlx->i % 10 == 3)
		fill_pixel(mlx, x, y, 0xffae19);
	else if (mlx->i % 10 == 4)
		fill_pixel(mlx, x, y, 0x45bbca);
	else if (mlx->i % 10 == 5)
		fill_pixel(mlx, x, y, 0x3da6b4);
	else if (mlx->i % 10 == 6)
		fill_pixel(mlx, x, y, 0x35919d);
	else if (mlx->i % 10 == 7)
		fill_pixel(mlx, x, y, 0x2e7c87);
	else if (mlx->i % 10 == 8)
		fill_pixel(mlx, x, y, 0x266870);
	else if (mlx->i % 10 == 9)
		fill_pixel(mlx, x, y, 0x1e535a);
}

static void	third_set(t_mlx *mlx, int x, int y)
{
	if (mlx->i % 10 == 0)
		fill_pixel(mlx, x, y, 0x000000);
	else if (mlx->i % 10 == 1)
		fill_pixel(mlx, x, y, 0x050017);
	else if (mlx->i % 10 == 2)
		fill_pixel(mlx, x, y, 0x1d192e);
	else if (mlx->i % 10 == 3)
		fill_pixel(mlx, x, y, 0x363245);
	else if (mlx->i % 10 == 4)
		fill_pixel(mlx, x, y, 0x504c5c);
	else if (mlx->i % 10 == 5)
		fill_pixel(mlx, x, y, 0xe51284);
	else if (mlx->i % 10 == 6)
		fill_pixel(mlx, x, y, 0xff1493);
	else if (mlx->i % 10 == 7)
		fill_pixel(mlx, x, y, 0xff5b9d);
	else if (mlx->i % 10 == 8)
		fill_pixel(mlx, x, y, 0xff42a8);
	else if (mlx->i % 10 == 9)
		fill_pixel(mlx, x, y, 0xff5ab3);
}

void		color(t_mlx *mlx, int x, int y)
{
	if (mlx->color_set == 1)
		first_set(mlx, x, y);
	else if (mlx->color_set == 2)
		second_set(mlx, x, y);
	else if (mlx->color_set == 3)
		third_set(mlx, x, y);
}
