/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:54:58 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/17 22:25:16 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

int		check_param(char *param)
{
	if (ft_strcmp(param, "Mandelbrot") == 0)
		return (0);
	else if (ft_strcmp(param, "Julia") == 0)
		return (1);
	return (-1);
}

int		usage(char *path)
{
	write(1, "usage : ", 8);
	write(1, path, ft_strlen(path));
	write(1, " [Mandelbrot] | [Julia]\n", 24);
	return (1);
}
