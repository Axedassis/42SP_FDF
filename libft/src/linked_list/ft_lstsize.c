/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:57:25 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/18 22:34:06 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		index;
	t_list	*tmp;

	tmp = lst;
	index = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}
