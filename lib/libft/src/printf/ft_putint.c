/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:41:49 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/21 15:56:53 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putint(int number)
{
	size_t	size_number;
	char	*str_number;

	size_number = 0;
	str_number = ft_itoa(number);
	size_number = ft_strlen(str_number);
	write(1, str_number, size_number);
	free(str_number);
	return (size_number);
}
