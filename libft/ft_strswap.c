/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:55:46 by jcreux            #+#    #+#             */
/*   Updated: 2019/06/02 19:46:40 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strswap(char *s)
{
	int		i;
	int		len;
	char	*new_s;

	i = 0;
	len = ft_strlen(s);
	if (!(new_s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > 0)
		new_s[i++] = s[len-- - 1];
	new_s[i] = '\0';
	return (new_s);
}
