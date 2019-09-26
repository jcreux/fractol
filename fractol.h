/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:06:19 by jcreux            #+#    #+#             */
/*   Updated: 2019/09/26 14:41:45 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** macros
*/
# define W_WIDTH	720
# define W_HEIGHT	480
# define CHAR_RANGE	256

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
	int		token;

	double	re;
	double	im;

	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

	double	zr;
	double	zi;
	double	nr;
	double	ni;
	double	or;
	double	oi;
}				t_mlx;

typedef struct	s_zoom
{
	double	r1;
	double	r2;
	double	new_r1;
	double	new_r2;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
}				t_zoom;

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
void			zoom(t_mlx *mlx, int x, int y, double k);
void			key_press2(int key, t_mlx *mlx);

#endif
