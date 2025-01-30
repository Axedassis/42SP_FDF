/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pts_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:13:29 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 20:42:22 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void set_color(char **str, t_pts *ptr);
static void	set_pt(char **str, int origin_x, int origin_y, t_pts *ptr);
static int	increase_ptr(int crr_n);


void	init_pts(t_map *map, char *readed_map)
{
	int		pts_count;
	char	*init_ptr;
	int		x;
	int		y;

	init_ptr = readed_map;
	x = 0;
	y = 0;
	pts_count = 0;
	while (*readed_map)
	{
		if (*readed_map == '-' || (*readed_map >= '0' && *readed_map <= '9'))
		{
			set_pt(&readed_map, x, y, &map->pts[y][x]);
			x++;
			pts_count++;
		}
		else if (*readed_map == ',')
			set_color(&readed_map, &map->pts[y][x - 1]);
		else if (*readed_map == '\n')
		{
			x = 0;
			y++;
			readed_map++;
		}
		else if (*readed_map == ' ')
			readed_map++;
	}
	free (init_ptr);
}

static void set_color(char **str, t_pts *ptr)
{
	*str += 3;
	ptr->color = ft_atoi_hexa(*str);
	while (**str != ' ' && **str && **str != '\n')
		(*str)++;
}

static void	set_pt(char **str, int origin_x, int origin_y, t_pts *ptr)
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
	while(tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}