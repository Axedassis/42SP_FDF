/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:17:18 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/19 20:19:03 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static int	getnb(char crr)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	while (base[i] && base[i] != crr)
		i++;
	return (i);
}

int	ft_atoi_hexa(char *str)
{
	int		i;
	int		hex;
	char	crr;

	i = 0;
	hex = 0;
	crr = 0;
	while (str[i] && str[i] != ' ')
	{
		crr = str[i];
		if (crr >= 97 && crr <= 102)
			crr = crr - 32;
		hex = (hex * 16) + getnb(crr);
		i++;
	}
	return (hex);
}