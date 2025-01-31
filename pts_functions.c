/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pts_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:13:29 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/31 13:54:37 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	increase_ptr(int crr_n);
static void	center_to_origin(t_map *map);

void	init_pts(t_map *map, char *readed_map)
{
	char	*init_ptr;

	init_ptr = readed_map;
	parse_map(map, readed_map);
	free(init_ptr);
	center_to_origin(map);
}

void	set_color(char **str, t_pts *ptr)
{
	*str += 3;
	ptr->color = ft_atoi_hexa(*str);
	while (**str != ' ' && **str && **str != '\n')
		(*str)++;
}

void	set_pt(char **str, int origin_x, int origin_y, t_pts *ptr)
{
	ptr->x = origin_x;
	ptr->y = origin_y;
	ptr->z = ft_atoi(*str);
	ptr->color = 0xFFFFFF;
	*str += increase_ptr(ptr->z);
}

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
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

static void	center_to_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->pts[x][y].x -= map->max_x / 2;
			map->pts[x][y].y -= map->max_y / 2;
			x++;
		}
		y++;
	}
}
