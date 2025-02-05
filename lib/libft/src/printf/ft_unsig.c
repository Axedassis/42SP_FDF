/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:41:43 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/21 13:44:12 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_unsig(unsigned int n)
{
	int		cnt;
	char	c;

	cnt = 0;
	if (n >= 10)
		cnt += ft_putint(n / 10);
	c = (n % 10) + '0';
	cnt += ft_putchar(c);
	return (cnt);
}
