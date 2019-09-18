/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:07:46 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/18 07:03:02 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_pixel(t_mlx *mlx, int x, int y, unsigned int color)
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
		fill_pixel(mlx, x, y, 0x005959);
	else if (mlx->i % 10 == 2)
		fill_pixel(mlx, x, y, 0x006666);
	else if (mlx->i % 10 == 3)
		fill_pixel(mlx, x, y, 0x007373);
	else if (mlx->i % 10 == 4)
		fill_pixel(mlx, x, y, 0x008080);
	else if (mlx->i % 10 == 5)
		fill_pixel(mlx, x, y, 0x405054);
	else if (mlx->i % 10 == 6)
		fill_pixel(mlx, x, y, 0x516469);
	else if (mlx->i % 10 == 7)
		fill_pixel(mlx, x, y, 0x627378);
	else if (mlx->i % 10 == 8)
		fill_pixel(mlx, x, y, 0x859296);
	else if (mlx->i % 10 == 9)
		fill_pixel(mlx, x, y, 0xcad0d2);
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
