/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:06:19 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/11 20:31:12 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** macros
*/
# define WIN_WIDTH	1440
# define WIN_HEIGHT	960
# define CHAR_RANGE	256

/*
** macros de touches
*/
# define ESC		53

/*
** declarations des structures
*/
typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		sl;
	int		en;

	int		i;
	int		fractal;
	int		iter;
	int		color_set;

	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

	double	z_r;
	double	z_i;
	double	new_r;
	double	new_i;
	double	old_r;
	double	old_i;
}				t_mlx;

typedef struct	s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_rgb;

/*
** prototypes des fonctions
*/
int				check_param(char *param);
int				usage(char *path);
void			create_fractal(t_mlx *mlx);
void			color(t_mlx *mlx, int x, int y);

#endif
