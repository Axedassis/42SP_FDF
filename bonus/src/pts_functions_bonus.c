/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pts_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:13:29 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/05 15:00:21 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static int	increase_ptr(int crr_n);
static void	center_to_origin(t_map *map);

void	init_pts(t_map *map, char *readed_map)
{
	char	*init_ptr;

	init_ptr = readed_map;
	parse_map(map, readed_map);
	center_to_origin(map);
	free(init_ptr);
}

void	set_color(char **str, t_pts *ptr)
{
	*str += 3;
	ptr->color = ft_atoi_hexa(*str);
	while (**str != ' ' && **str && **str != '\n')
		(*str)++;
}

void	set_pt(char **str, int origin_x, int origin_y, t_map *map)
{
	int		nbr;

	nbr = ft_atoi(*str);
	map->pts[origin_y][origin_x].x = origin_x;
	map->pts[origin_y][origin_x].y = origin_y;
	map->pts[origin_y][origin_x].z = nbr;
	map->pts[origin_y][origin_x].color = COL_DEFAULT;
	*str += increase_ptr(map->pts[origin_y][origin_x].z);
	if (nbr < map->min_z)
		map->min_z = nbr;
	if (nbr > map->max_z)
		map->max_z = nbr;
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
			map->pts[x][y].x -= map->max_y / 2;
			map->pts[x][y].y -= map->max_x / 2;
			x++;
		}
		y++;
	}
}
