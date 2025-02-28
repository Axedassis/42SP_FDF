/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:36:45 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/05 15:00:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

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
	print_menu(mlx);
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
	rotate(&mlx->cam, line);
	projection(mlx, line);
	center(mlx, line);
	bresenhams(mlx, line);
	free (line);
}

static t_line	*init_line(t_mlx *mlx, t_pts start, t_pts end)
{
	t_line	*line;
	float	factory_z;

	factory_z = mlx->cam.scale_factory * mlx->cam.scale_factory_z;
	apply_color(mlx, &start);
	apply_color(mlx, &end);
	line = (t_line *)malloc(sizeof(t_line) * 1);
	if (!line)
		close_window(mlx);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z * factory_z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z * factory_z;
	line->end.color = end.color;
	return (line);
}
