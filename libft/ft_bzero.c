/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:22:01 by jcreux            #+#    #+#             */
/*   Updated: 2018/12/14 05:39:27 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr_s;

	i = 0;
	ptr_s = s;
	while (i < n)
	{
		ptr_s[i] = '\0';
		i++;
	}
}
