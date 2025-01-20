/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pts_populate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:40:58 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/19 20:40:32 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static int	increase_ptr(int crr_n)
{
	int		i;
	int		tmp;

	tmp = crr_n;
	i = 0;
	if (tmp == 0)
		return (1);
	if (tmp < 0)
	{
		i++;
		tmp = abs(tmp);
	}
	while(tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

static void	set_pt(char **str, int origin_x, int origin_y, t_point *ptr)
{
	ptr->x = origin_x;
	ptr->y = origin_y;
	ptr->z = ft_atoi(*str);
	if (ptr->z <= 0)
		ptr->color = 0xFFFFFF;
	else
		ptr->color = 0xFFFFF + (8352782 * ptr->z);
	*str += increase_ptr(ptr->z);
}

static void set_color(char **str, t_point *ptr)
{
	*str += 3;
	ptr->color = ft_atoi_hexa(*str);
	while (**str != ' ' && **str != 0 && **str != '\n')
		*str = *str + 1;
}

void	set_pts(t_mlx *mlx, char *str)
{
	int		i;
	int		x;
	int		y;

	x = mlx->data_map.origin_x;
	y = mlx->data_map.origin_y;

	i = 0;
	while (*str)
	{
		if (*str == '-' || (*str >= '0' && *str <= '9'))
		{
			x += mlx->data_map.mult;
			set_pt(&str, x, y, &mlx->pts[i]);
			i++;
		}
		else if (*str == ',')
			set_color(&str, &mlx->pts[i - 1]);
		else if (*str == '\n')
		{
			x = mlx->data_map.origin_x;
			y += mlx->data_map.mult;
			str++;
		}
		else if(*str == ' ')
			str++;
	}
}