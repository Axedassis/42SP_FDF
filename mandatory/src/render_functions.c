/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:36:45 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/05 14:58:03 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		scale(t_mlx *mlx, t_line *line);
static void		center(t_mlx *mlx, t_line *line);
static void		draw_line(t_mlx *mlx, t_pts start, t_pts end);
static t_line	*init_line(t_mlx *mlx, t_pts start, t_pts end);

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

static void	scale(t_mlx *mlx, t_line *line)
	{
	float	scale;

	scale = mlx->cam.scale_factory;
	line->start.x *= scale;
	line->start.y *= scale;
	line->end.x *= scale;
	line->end.y *= scale;
}

static void	center(t_mlx *mlx, t_line *line)
{
	line->start.x += mlx->cam.mv_x;
	line->start.y += mlx->cam.mv_y;
	line->end.x += mlx->cam.mv_x;
	line->end.y += mlx->cam.mv_y;
}

static void	draw_line(t_mlx *mlx, t_pts start, t_pts end)
{
	t_line	*line;

	line = init_line(mlx, start, end);
	scale(mlx, line);
	isometric(line);
	center(mlx, line);
	bresenhams(mlx, line);
	free (line);
}

static t_line	*init_line(t_mlx *mlx, t_pts start, t_pts end)
{
	t_line	*line;
	float	z_range;
	float	z_multiplier;

	apply_color(mlx, &start);
	apply_color(mlx, &end);
	z_range = mlx->map.max_z + abs(mlx->map.min_z);
	if (z_range > 50)
		z_multiplier = 1;
	else
		z_multiplier = 8;
	start.z *= z_multiplier;
	end.z *= z_multiplier;
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
