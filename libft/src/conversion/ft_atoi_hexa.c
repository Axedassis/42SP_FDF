/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:17:00 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 18:33:05 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	getnb(char c)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_hexa(char *str)
{
	int		i;
	int		res;
	char	c;

	i = -1;
	res = 0;
	c = 0;
	while (i++, str[i] && str[i] != ' ')
	{
		c = str[i];
		if (c >= 97 && c <= 102)
			c = c - 32;
		res = (res * 16) + getnb(c);
	}
	return (res);
}
