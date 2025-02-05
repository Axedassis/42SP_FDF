/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:27:04 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/05 14:57:06 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, const char **argv)
{
	t_mlx		*mlx;
	const char	*path_file;

	if (argc == 2)
	{
		path_file = argv[1];
		if (file_format(path_file) == -1)
			exit(EXIT_FAILURE);
		mlx = init_fdf(path_file);
		init_mlx(mlx);
		init_cam(mlx);
		init_render(mlx);
		mlx_loop(mlx->mlx);
	}
	else
		error_exit("Number of invalid arguments, maximum 1", 1);
	return (0);
}

void	set_to_null(t_mlx *mlx)
{
	mlx->cam = (t_cam){0};
	mlx->img = (t_data){0};
	mlx->map = (t_map){0};
	mlx->mlx = NULL;
	mlx->win = NULL;
}

float	get_scale(t_mlx *mlx)
{
	float	scale;
	float	scale_x;
	float	scale_y;

	scale_x = WIN_WIDTH / (float)mlx->map.max_x;
	scale_y = WIN_HEIGHT / (float)mlx->map.max_y;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale / 1.75);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
}
