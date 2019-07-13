/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:11:14 by jcreux            #+#    #+#             */
/*   Updated: 2019/05/31 20:03:39 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishexa(int c)
{
	if (ft_isdigit(c) == 1 || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (0);
	return (1);
}