/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:07:46 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/11 20:30:24 by jcreux           ###   ########.fr       */
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
	if (mlx->i % 5 == 0)
		fill_pixel(mlx, x, y, 0xfec83d);
	else if (mlx->i % 5 == 1)
		fill_pixel(mlx, x, y, 0xfec228);
	else if (mlx->i % 5 == 2)
		fill_pixel(mlx, x, y, 0xe4ae24);
	else if (mlx->i % 5 == 3)
		fill_pixel(mlx, x, y, 0xcb9b20);
	else if (mlx->i % 5 == 4)
		fill_pixel(mlx, x, y, 0xb1871c);
}

static void	second_set(t_mlx *mlx, int x, int y)
{
	if (mlx->i % 5 == 0)
		fill_pixel(mlx, x, y, 0xff0000);
	else if (mlx->i % 5 == 1)
		fill_pixel(mlx, x, y, 0xe50000);
	else if (mlx->i % 5 == 2)
		fill_pixel(mlx, x, y, 0xcc0000);
	else if (mlx->i % 5 == 3)
		fill_pixel(mlx, x, y, 0xb20000);
	else if (mlx->i % 5 == 4)
		fill_pixel(mlx, x, y, 0x990000);
}

static void	third_set(t_mlx *mlx, int x, int y)
{
	if (mlx->i % 5 == 0)
		fill_pixel(mlx, x, y, 0x327eac);
	else if (mlx->i % 5 == 1)
		fill_pixel(mlx, x, y, 0x196fa2);
	else if (mlx->i % 5 == 2)
		fill_pixel(mlx, x, y, 0x005f98);
	else if (mlx->i % 5 == 3)
		fill_pixel(mlx, x, y, 0x005588);
	else if (mlx->i % 5 == 4)
		fill_pixel(mlx, x, y, 0x004c79);
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
