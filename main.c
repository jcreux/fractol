/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:01:16 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/11 20:02:15 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fractol.h"

static void	zoom(t_mlx *mlx, double c)
{
	double	r1;
	double	r2;

	r1 = (mlx->x_max - mlx->x_min) * c;
	r2 = (mlx->y_max - mlx->y_min) * c;
	mlx->x_max -= (mlx->x_max - mlx->x_min) - r1;
	mlx->y_max -= (mlx->y_max - mlx->y_min) - r2;
}

static int	leave(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(1);
}

static int	key_press(int key, t_mlx *mlx)
{
	if (key == ESC)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(1);
	}
	else if (key == 69)
		zoom(mlx, 0.95);
	else if (key == 78)
		zoom(mlx, 1.05);
	else if (key == 126)
		mlx->iter++;
	else if (key == 125 && mlx->iter > 0)
		mlx->iter--;
	else if (key == 83)
		mlx->color_set = 1;
	else if (key == 84)
		mlx->color_set = 2;
	else if (key == 85)
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
	mlx_hook(mlx.win_ptr, 17, 0, leave, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
