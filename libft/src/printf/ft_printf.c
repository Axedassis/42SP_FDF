/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:24:57 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/29 17:29:27 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void	ft_format(char specifier, va_list valist, int *cnt)
{
	if (specifier == 'c')
		*cnt += ft_putchar(va_arg(valist, int));
	if (specifier == 's')
		*cnt += ft_putstr(va_arg(valist, char *));
	if (specifier == 'd' || specifier == 'i')
		*cnt += ft_putint(va_arg(valist, int));
	if (specifier == 'p')
		*cnt += ft_putpnt(va_arg(valist, unsigned long));
	if (specifier == 'u')
		*cnt += ft_unsig(va_arg(valist, unsigned int));
	if (specifier == 'x' || specifier == 'X')
		*cnt += ft_puthex(va_arg(valist, unsigned int), specifier);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cnt;
	va_list	valist;

	i = 0;
	cnt = 0;
	if (!str)
		return (-1);
	va_start(valist, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				cnt += ft_putchar('%');
			else
				ft_format(str[i], valist, &cnt);
		}
		else
			cnt += ft_putchar(str[i]);
		i++;
	}
	va_end(valist);
	return (cnt);
}
