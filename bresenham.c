/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:47:05 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 23:28:18 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_to_image(t_data *image, float x, float y, int color)
{
	int	pixel;

	if (x < 0 || x >= IMG_WIDTH || y < 0 || y >= IMG_HEIGHT)
		return;

	pixel = ((int)y * image->line_length) + ((int)x * 4);
	if (image->endian == 1)
	{
		image->addr[pixel + 0] = (color >> 24);
		image->addr[pixel + 1] = (color >> 16) & 0xff;
		image->addr[pixel + 2] = (color >> 8) & 0xff;
		image->addr[pixel + 3] = (color) & 0xff;
	}
	else if (image->endian == 0)
	{
		image->addr[pixel + 0] = (color) & 0xff;
		image->addr[pixel + 1] = (color >> 8) & 0xff;
		image->addr[pixel + 2] = (color >> 16) & 0xff;
		image->addr[pixel + 3] = (color >> 24);
	}
}


void bresenhams(t_mlx *mlx, t_line *line)
{
	int dx, dy, p, x, y, x_end, y_end;
	int init_color;

	dx = abs(line->end.x - line->start.x);
	dy = abs(line->end.y - line->start.y);
	x = line->start.x;
	y = line->start.y;
	x_end = line->end.x;
	y_end = line->end.y;
	init_color = line->start.color;

	int max_steps = (int)fmax(dx, dy);
	int steps = 0;

	int sx = (line->start.x < line->end.x) ? 1 : -1;
	int sy = (line->start.y < line->end.y) ? 1 : -1;

	if (dx > dy)
	{
		p = 2 * dy - dx;
		while (steps <= dx)
		{
			// teste = get_color(color, steps, max_steps);
			// line->start.color = teste;
			pixel_to_image(&mlx->img, x, y, line->start.color);
			if (p >= 0)
			{
				y += sy;
				p -= 2 * dx;
			}
			p += 2 * dy;
			x += sx;
			steps++;
		}
	}
	else
	{
		p = 2 * dx - dy;
		while (steps <= dy)
		{
			pixel_to_image(&mlx->img, x, y, line->start.color);
			if (p >= 0)
			{
				x += sx;
				p -= 2 * dy;
			}
			p += 2 * dx;
			y += sy;
			steps++;
		}
	}
}
