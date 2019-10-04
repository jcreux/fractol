/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:16:47 by jcreux            #+#    #+#             */
/*   Updated: 2019/10/04 10:18:29 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_press2(int key, t_mlx *mlx)
{
	if (key == TAB)
	{
		if (mlx->fractal == 2)
			mlx->fractal = 0;
		else
			mlx->fractal++;
	}
	else if (key == SPACE)
	{
		if (mlx->token == 0)
			mlx->token = 1;
		else
			mlx->token = 0;
	}
}

void	zoom(t_mlx *mlx, int x, int y, double k)
{
	t_zoom	zoom;

	zoom.xmin = (double)x / W_WIDTH;
	zoom.xmax = 1 - ((double)x / W_WIDTH);
	zoom.ymin = (double)y / W_HEIGHT;
	zoom.ymax = 1 - ((double)y / W_HEIGHT);
	zoom.r1 = (mlx->x_max - mlx->x_min) * k;
	zoom.r2 = (mlx->y_max - mlx->y_min) * k;
	zoom.new_r1 = (mlx->x_max - mlx->x_min) - zoom.r1;
	zoom.new_r2 = (mlx->y_max - mlx->y_min) - zoom.r2;
	mlx->x_max -= zoom.new_r1 * zoom.xmax;
	mlx->x_min += zoom.new_r1 * zoom.xmin;
	mlx->y_max -= zoom.new_r2 * zoom.ymax;
	mlx->y_min += zoom.new_r2 * zoom.ymin;
}
