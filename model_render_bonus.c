/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:07 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/04 01:51:01 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	side_parallel(t_line *line);
static void	isometric(t_line *line);

void	projection(t_mlx *mlx, t_line *line)
{
	if (mlx->cam.project == 1)
		isometric(line);
	else if (mlx->cam.project == 2)
		side_parallel(line);
	else if (mlx->cam.project == 3)
		return ;
}

static void	isometric(t_line *line)
{
	t_pts	new_start;
	t_pts	new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_start.y = (line->start.x + line->start.y) * sin(ANG_30)
		- line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_end.y = (line->end.x + line->end.y) * sin(ANG_30)
		- line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

static void	side_parallel(t_line *line)
{
	t_pts	new_start;
	t_pts	new_end;

	new_start.x = line->start.y;
	new_start.y = -line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = line->end.y;
	new_end.y = -line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}
