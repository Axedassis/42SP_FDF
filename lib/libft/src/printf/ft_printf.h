/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:25:03 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/21 18:12:05 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char letter);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
char	*ft_itoa(int number);
int		ft_putint(int number);
int		ft_putpnt(unsigned long pnt);
int		ft_unsig(unsigned int n);
int		ft_puthex(unsigned long value, char specifier);

#endif