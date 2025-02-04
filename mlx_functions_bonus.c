/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:02:08 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/04 00:48:47 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	init_img(t_mlx *mlx);

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		free_pts(mlx);
		free(mlx);
		error_exit ("Error initializing MLX", 8);
	}
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free_pts(mlx);
		free(mlx);
		error_exit ("Error initializing MLX WIN", 9);
	}
	init_img(mlx);
	mlx_hook(mlx->win, 17, 1L << 0, close_window, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
}

static void	init_img(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!mlx->img.img)
	{
		mlx_destroy_display(mlx->mlx);
		free_pts(mlx);
		free(mlx);
		error_exit("Error creating new image", 10);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	if (!mlx->img.addr)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_display(mlx->mlx);
		free_pts(mlx);
		free(mlx);
		error_exit("Error getting image data address", 11);
	}
}
