/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:47:05 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/03 16:50:20 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		determine_steps(t_line *line, int *sx, int *sy);
static void		draw_shallow_line(t_mlx *mlx, t_line *line, t_delta delta);
static void		draw_steep_line(t_mlx *mlx, t_line *line, t_delta delta);

void	bresenhams(t_mlx *mlx, t_line *line)
{
	t_delta	delta;
	t_color	*color;

	delta.color = init_pallet(line->start.color, line->end.color);
	delta.dx = abs(line->end.x - line->start.x);
	delta.dy = abs(line->end.y - line->start.y);
	determine_steps(line, &delta.sx, &delta.sy);
	if (delta.dx > delta.dy)
		draw_shallow_line(mlx, line, delta);
	else
		draw_steep_line(mlx, line, delta);
	free(delta.color);
}

static void	determine_steps(t_line *line, int *sx, int *sy)
{
	if (line->start.x < line->end.x)
		*sx = 1;
	else
		*sx = -1;
	if (line->start.y < line->end.y)
		*sy = 1;
	else
		*sy = -1;
}

static void	draw_shallow_line(t_mlx *mlx, t_line *line, t_delta delta)
{
	int		p;
	int		x;
	int		y;
	int		steps;

	p = 2 * delta.dy - delta.dx;
	x = line->start.x;
	y = line->start.y;
	steps = 0;
	while (steps <= delta.dx)
	{
		line->start.color = get_color(delta.color, steps,
				fmax(delta.dx, delta.dy));
		pixel_to_image(&mlx->img, x, y, line->start.color);
		if (p >= 0)
		{
			y += delta.sy;
			p -= 2 * delta.dx;
		}
		p += 2 * delta.dy;
		x += delta.sx;
		steps++;
	}
}

static void	draw_steep_line(t_mlx *mlx, t_line *line, t_delta delta)
{
	int		p;
	int		x;
	int		y;
	int		steps;

	p = 2 * delta.dx - delta.dy;
	x = line->start.x;
	y = line->start.y;
	steps = 0;
	while (steps <= delta.dy)
	{
		line->start.color = get_color(delta.color, steps,
				fmax(delta.dx, delta.dy));
		pixel_to_image(&mlx->img, x, y, line->start.color);
		if (p >= 0)
		{
			x += delta.sx;
			p -= 2 * delta.dy;
		}
		p += 2 * delta.dx;
		y += delta.sy;
		steps++;
	}
}
