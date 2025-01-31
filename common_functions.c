/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:43:40 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 21:10:51 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx->map.pts = (t_pts **)malloc(sizeof(t_pts *) * mlx->map.max_y);
	if (!mlx->map.pts)
	{
		free(mlx);
		free(readed_map);
		error_exit("Memory allocation failed for mlx->map.pts", 6);
	}
	while (j < mlx->map.max_y)
	{
		mlx->map.pts[j] = (t_pts *)malloc(sizeof(t_pts) * mlx->map.max_x);
		if (!mlx->map.pts[j])
		{
			while (i++ < j)
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
		while (i < mlx->map.max_y)
		{
			if (mlx->map.pts[i])
				free(mlx->map.pts[i]);
			i++;
		}
		free(mlx->map.pts);
		mlx->map.pts = NULL;
	}
}


