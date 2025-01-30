/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:24:58 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/21 16:58:51 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_strlen(char *str)
{
	int	str_length;

	str_length = 0;
	if (!str)
		return (str_length);
	while (str[str_length])
		str_length++;
	return (str_length);
}
