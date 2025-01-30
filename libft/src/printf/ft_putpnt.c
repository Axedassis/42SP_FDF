/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:01:43 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 18:31:58 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	calc_size(unsigned long number)
{
	int	length;

	length = 0;
	if (number == 0)
		length = 1;
	while (number)
	{
		number /= 16;
		length++;
	}
	return (length);
}

static char	*to_hex(unsigned long pnt)
{
	char	*hex_pnt;
	char	*hex;
	int		size_hex;

	hex = "0123456789abcdef";
	size_hex = calc_size(pnt);
	hex_pnt = (char *)malloc(size_hex + 1);
	if (!hex_pnt)
		return (NULL);
	hex_pnt[size_hex] = '\0';
	while (size_hex--)
	{
		hex_pnt[size_hex] = hex[(pnt % 16)];
		pnt = pnt / 16;
	}
	return (hex_pnt);
}

int	ft_putpnt(unsigned long pnt)
{
	char	*hex_pnt;
	int		hex_size;

	if (pnt == 0)
		return (write(1, "(nil)", 5));
	hex_pnt = to_hex(pnt);
	if (!hex_pnt)
		return (0);
	hex_size = ft_strlen(hex_pnt);
	write(1, "0x", 2);
	write(1, hex_pnt, hex_size);
	free(hex_pnt);
	return (hex_size + 2);
}
