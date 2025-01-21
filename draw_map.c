/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:44:12 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/20 23:24:24 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	getpixels(t_point pts1, t_point pts2)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltax = pts2.x - pts1.x;
	deltay = pts2.y - pts1.y;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	return (pixels);
}

void	ft_drawline(t_point pts1, t_point pts2, t_mlx *mlx)
{
	t_delta d;


	d.deltax = pts2.x - pts1.x;
	d.deltay = pts2.y - pts1.y;
	d.pixels = getpixels(pts1, pts2);
	d.deltax /= d.pixels;
	d.deltay /= d.pixels;
	d.x = pts1.x;
	d.y = pts1.y;
	d.c = pts1.color;
	d.deltacolor = pts2.color - pts1.color;
	d.deltacolor /= d.pixels;
	while (d.pixels)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, d.x, d.y, d.c);
		d.x += d.deltax;
		d.y += d.deltay;
		d.c += d.deltacolor;
		d.pixels--;
	}
}

void	render_columns(t_mlx *mlx)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < mlx->data_map.columns)
	{
		while (j < mlx->data_map.rows - 1)
		{
			ft_drawline(mlx->pts[i], mlx->pts[i + mlx->data_map.columns], mlx);
			i = i + mlx->data_map.columns;
			j++;
		}
		j = 0;
		k++;
		i = k;
	}
}

int	render_rows(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (mlx->data_map.size - 1))
	{
		ft_drawline(mlx->pts[i], mlx->pts[i + 1], mlx);
		i++;
		j++;
		if (j == mlx->data_map.columns - 1)
		{
			i++;
			j = 0;
		}
	}
}


int	render_map(t_mlx *mlx)
{
	render_rows(mlx);
	render_columns(mlx);
}