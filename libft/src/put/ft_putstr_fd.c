/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:18:40 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/18 22:33:20 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_size;

	s_size = ft_strlen(s);
	if (s_size == 2147483647)
		return ;
	write(fd, s, s_size);
}
