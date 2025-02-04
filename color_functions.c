/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:02:44 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/03 16:50:46 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color_gradient(t_color *color, float progress)
{
	int	r;
	int	g;
	int	b;

	r = color->delta_r * progress;
	if (r < -255)
		r = 0;
	else if (r > 255)
		r = 255;
	r = r << 16;
	g = color->delta_g * progress;
	if (g < -255)
		g = 0;
	else if (g > 255)
		g = 255;
	g = g << 8;
	b = color->delta_b * progress;
	if (b < -255)
		b = 0;
	else if (b > 255)
		b = 255;
	return (color->start_color + r + g + b);
}

int	get_color(t_color *color, int crr_val, int max_val)
{
	float	progression;

	if (max_val == 0)
		return (color->start_color);
	progression = (float)crr_val / (float)max_val;
	return (color_gradient(color, progression));
}

t_color	*init_pallet(int col_start, int col_end)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->start_color = col_start;
	color->start_r = (MSK_RED & col_start) >> 16;
	color->start_g = (MSK_GREEN & col_start) >> 8;
	color->start_b = (MSK_BLUE & col_start);
	color->end_color = col_end;
	color->end_r = (MSK_RED & col_end) >> 16;
	color->end_g = (MSK_GREEN & col_end) >> 8;
	color->end_b = (MSK_BLUE & col_end);
	color->delta_r = (color->end_r - color->start_r);
	color->delta_g = (color->end_g - color->start_g);
	color->delta_b = (color->end_b - color->start_b);
	return (color);
}

void	apply_color(t_mlx *mlx, t_pts *pts)
{
	t_color	*color;

	if (pts->color == 0xFFFFFF && mlx->map.h_col == 0)
	{
		color = init_pallet(COL_GREEN, COL_BLUE);
		pts->color = get_color(color, pts->z, abs(mlx->map.max_z));
		free (color);
	}
	else if (pts->color == 0)
	{
		pts->color = COL_DEFAULT;
	}
}
