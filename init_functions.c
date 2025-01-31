/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:55:25 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 23:22:24 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_pts(t_mlx *mlx) // !REMOVEEEEE
{
	for (int i = 0; i < mlx->map.max_y; i++)
	{
		for (int j = 0; j < mlx->map.max_x; j++)
		{
			printf("Point[%d][%d]: x = %d, y = %d, z = %d, color = %#x\n", i, j, mlx->map.pts[j][i].x, mlx->map.pts[j][i].y, mlx->map.pts[j][i].z, mlx->map.pts[j][i].color);
		}
	}
}

void	init_cam(t_mlx *mlx)
{
	mlx->cam.mv_x = WIN_WIDTH / 2;
	mlx->cam.mv_y = WIN_HEIGHT / 2;
	mlx->cam.scale_factory = fmin((WIN_WIDTH / mlx->map.max_x), (WIN_HEIGHT / mlx->map.max_y));
	mlx->cam.alpha = 0;
	mlx->cam.beta = 0;
	mlx->cam.gamma = 0;
}

t_mlx	*init_fdf(const char *path_file)
{
	t_mlx	*mlx;
	char	*readed_map;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		error_exit("Memory allocation failure", 2);
	readed_map = init_map(mlx, path_file);
	init_malloc_pts(mlx, readed_map);
	init_pts(&mlx->map, readed_map);
	// print_pts(mlx);
	return (mlx);
}