/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:43:40 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/05 14:59:28 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	error_exit(const char *msg, int code)
{
	if (code != 0)
	{
		ft_printf("%s\n", msg);
		exit (code);
	}
	ft_printf("%s\n", msg);
	exit (-1);
}

void	init_malloc_pts(t_mlx *mlx, char *readed_map)
{
	int		j;
	int		i;

	j = 0;
	i = -1;
	mlx->map.pts = (t_pts **)malloc(sizeof(t_pts *) * mlx->map.max_x);
	if (!mlx->map.pts)
	{
		free(mlx);
		free(readed_map);
		error_exit("Memory allocation failed for mlx->map.pts", 6);
	}
	while (j < mlx->map.max_x)
	{
		mlx->map.pts[j] = (t_pts *)malloc(sizeof(t_pts) * mlx->map.max_y);
		if (!mlx->map.pts[j])
		{
			i = -1;
			while (++i < j)
				free(mlx->map.pts[i]);
			error_exit("Memory allocation failed for mlx->map.pts", 7);
		}
		j++;
	}
}

void	free_pts(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->map.pts)
	{
		while (i < mlx->map.max_x)
		{
			if (mlx->map.pts[i])
				free(mlx->map.pts[i]);
			i++;
		}
		free(mlx->map.pts);
	}
}

void	clear_buffer(t_data *img)
{
	int	x;
	int	y;

	ft_bzero(img->addr, 50000);
	y = 0;
	while (y < IMG_HEIGHT)
	{
		x = 0;
		while (x < IMG_WIDTH)
		{
			pixel_to_image(img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

int	close_window(t_mlx *mlx)
{
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->map.pts)
		free_pts(mlx);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free(mlx);
	ft_printf("FDF closed\n");
	exit(0);
}
