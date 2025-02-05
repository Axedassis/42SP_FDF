/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:51:30 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/21 18:08:01 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_puthex(unsigned long value, char specifier)
{
	int		hex_size;
	char	*hex;

	hex_size = 0;
	if (specifier == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (value == 0)
		return (ft_putchar('0'));
	else
	{
		if (value / 16 > 0)
			hex_size += ft_puthex(value / 16, specifier);
		hex_size += ft_putchar(hex[value % 16]);
	}
	return (hex_size);
}
