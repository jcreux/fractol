/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:01:16 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/18 07:02:18 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fractol.h"

static void	zoom(t_mlx *mlx, int x, int y, double k)
{
	t_zoom	zoom;

	zoom.xmin = (double)x / 1440;
	zoom.xmax = 1 - ((double)x / 1440);
	zoom.ymin = (double)y / 960;
	zoom.ymax = 1 - ((double)y / 960);
	zoom.r1 = (mlx->x_max - mlx->x_min) * k;
	zoom.r2 = (mlx->y_max - mlx->y_min) * k;
	zoom.new_r1 = (mlx->x_max - mlx->x_min) - zoom.r1;
	zoom.new_r2 = (mlx->y_max - mlx->y_min) - zoom.r2;
	mlx->x_max -= zoom.new_r1 * zoom.xmax;
	mlx->x_min += zoom.new_r1 * zoom.xmin;
	mlx->y_max -= zoom.new_r2 * zoom.ymax;
	mlx->y_min += zoom.new_r2 * zoom.ymin;
}

static int	leave(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(1);
}

static int	mouse_press(int key, int x, int y, t_mlx *mlx)
{
	if (key == 4)
		zoom(mlx, x, y, 1.2);
	else if (key == 5)
		zoom(mlx, x, y, 0.8);
	create_fractal(mlx);
	return (0);
}

static int	key_press(int key, t_mlx *mlx)
{
	if (key == ESC)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(1);
	}
	else if (key == 126)
		mlx->iter++;
	else if (key == 125 && mlx->iter > 0)
		mlx->iter--;
	else if (key == 18)
		mlx->color_set = 1;
	else if (key == 19)
		mlx->color_set = 2;
	else if (key == 20)
		mlx->color_set = 3;
	create_fractal(mlx);
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2 || (mlx.fractal = check_param(av[1])) == -1)
		return (usage(av[0]));
	mlx.x_min = -2;
	mlx.x_max = 1;
	mlx.y_min = -1;
	mlx.y_max = 1;
	mlx.iter = 20;
	mlx.color_set = 1;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fract'ol");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img_data = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.sl, &mlx.en);
	create_fractal(&mlx);
	mlx_hook(mlx.win_ptr, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win_ptr, 4, 0, mouse_press, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, leave, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
