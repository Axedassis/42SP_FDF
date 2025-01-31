/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:36:45 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/31 12:33:46 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void scale(t_mlx *mlx, t_line *line);
static void center(t_mlx *mlx, t_line *line);
static void draw_line(t_mlx *mlx, t_pts start, t_pts end);
static t_line *init_line(t_mlx *mlx, t_pts start, t_pts end);

void	init_render(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;

	clear_buffer(&mlx->img);
	while (y < mlx->map.max_y)
	{
		x = 0;
		while (x < mlx->map.max_x)
		{
			if (x < mlx->map.max_x - 1)
				draw_line(mlx, mlx->map.pts[x][y], mlx->map.pts[x + 1][y]);
			if (y < mlx->map.max_y - 1)
				draw_line(mlx, mlx->map.pts[x][y], mlx->map.pts[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

static void scale(t_mlx *mlx, t_line *line)
	{
	float		scale = mlx->cam.scale_factory * 0.5;
	line->start.x *= scale;
	line->start.y *= scale;
	line->end.x *= scale;
	line->end.y *= scale;
}

static void center(t_mlx *mlx, t_line *line)
{
	line->start.x += mlx->cam.mv_x;
	line->start.y += mlx->cam.mv_y;
	line->end.x += mlx->cam.mv_x;
	line->end.y += mlx->cam.mv_y;
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

static void draw_line(t_mlx *mlx, t_pts start, t_pts end)
{
	t_line	*line = init_line(mlx, start, end);
	scale(mlx, line);
	isometric(line);
	center(mlx, line);
	bresenhams(mlx, line);
	free (line);
}

static t_line *init_line(t_mlx *mlx, t_pts start, t_pts end)
{
	t_line	*line;
	start.z *= mlx->cam.scale_factory;
	end.z *= mlx->cam.scale_factory;

	line = (t_line *)malloc(sizeof(t_line) * 1);
	if (!line)
		close_window(mlx);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;

	return (line);
}