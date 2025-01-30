/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:29:38 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/21 12:56:17 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	ft_len_sign(int number, int *nonpositive_ptr)
{
	int	len;

	if (number <= 0)
		*nonpositive_ptr = 1;
	else
		*nonpositive_ptr = 0;
	len = 0;
	while (number)
	{
		number /= 10;
		len++;
	}
	return (len + *nonpositive_ptr);
}

static void	ft_fill_string(char *string, int last, \
	int number, int negative)
{
	if (number == 0)
	{
		string[last] = '0';
		return ;
	}
	while (number)
	{
		if (negative)
			string[last--] = 48 + ((number % 10) * (-1));
		else
			string[last--] = 48 + (number % 10);
		number /= 10;
	}
}

char	*ft_itoa(int number)
{
	int		len;
	int		nonpositive;
	char	*string;

	len = ft_len_sign(number, &nonpositive);
	string = (char *)malloc((size_t)(len + 1) * sizeof(char));
	if (!(string))
		return ((void *)0);
	string[len] = '\0';
	if (number == 0)
		string[0] = '0';
	if (number < 0)
		string[0] = '-';
	ft_fill_string(string, (len - 1), number, nonpositive);
	return (string);
}
