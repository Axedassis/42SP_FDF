/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:55:25 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 20:14:48 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*init_fdf(const char *path_file)
{
	t_mlx	*mlx;
	char	*readed_map;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		error_exit("Memory allocation failure", 2);
	readed_map = init_map(mlx, path_file);
	init_pts(mlx, readed_map);

	return (mlx);
}