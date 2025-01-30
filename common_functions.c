/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:43:40 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 18:45:58 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(const char *msg, int code)
{
	if (code != 0)
	{
		ft_printf("%s\n", msg);
		exit (code);
	}
	ft_printf("%s\n", msg);
	exit (-1);
}