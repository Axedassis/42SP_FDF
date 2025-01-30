/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:55:25 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 20:45:03 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_pts(t_mlx *mlx)
{
	for (int i = 0; i < mlx->map.max_y; i++)
	{
		for (int j = 0; j < mlx->map.max_x; j++)
		{
			printf("Point[%d][%d]: x = %d, y = %d, z = %d, color = %#x\n", i, j, mlx->map.pts[j][i].x, mlx->map.pts[j][i].y, mlx->map.pts[j][i].z, mlx->map.pts[j][i].color);
		}
	}
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
	print_pts(mlx);

	return (mlx);
}