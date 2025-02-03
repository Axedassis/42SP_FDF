/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:55:25 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/03 15:18:04 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	node_parse(int *x, int *y, char **map);

//? VERIFY
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
	if (scale < 3)
		scale = 3;
	if (scale > 60)
		scale = 50;
	return (scale / 1.7);
}

void	init_cam(t_mlx *mlx)
{
	mlx->cam.mv_x = WIN_WIDTH / 2;
	mlx->cam.mv_y = WIN_HEIGHT / 2;
	mlx->cam.scale_factory = get_scale(mlx);
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
	set_to_null(mlx);
	readed_map = init_map(mlx, path_file);
	init_malloc_pts(mlx, readed_map);
	init_pts(&mlx->map, readed_map);
	return (mlx);
}

void	pixel_to_image(t_data *image, float x, float y, int color)
{
	int	pixel;

	if (x < 0 || x >= IMG_WIDTH || y < 0 || y >= IMG_HEIGHT)
		return ;
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

void	parse_map(t_map *map, char *readed_map)
{
	int		x;
	int		y;
	int		pts_count;

	x = 0;
	y = 0;
	pts_count = 0;
	while (*readed_map)
	{
		if (*readed_map == '-' || (*readed_map >= '0' && *readed_map <= '9'))
		{
			set_pt(&readed_map, x, y, map);
			x++;
			pts_count++;
		}
		else if (*readed_map == ',')
			set_color(&readed_map, &map->pts[y][x - 1], map);
		else if (*readed_map == '\n')
			node_parse(&x, &y, &readed_map);
		else if (*readed_map == ' ')
			readed_map++;
	}
}

static void	node_parse(int *x, int *y, char **map)
{
	*x = 0;
	*y = *y + 1;
	(*map)++;
}
