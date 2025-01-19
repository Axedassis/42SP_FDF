/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:10:53 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/18 22:33:20 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*cptr;

	i = 0;
	cptr = (char *)s;
	while (i++ < n)
	{
		*cptr = c;
		cptr++;
	}
	return (s);
}
