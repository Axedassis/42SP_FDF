/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:54:55 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/19 20:41:09 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	error_exit(const char *msg, int code)
{
	perror(msg);
	exit (code);
}

int	check_path(const char *f_name)
{
	int		i;

	if (!f_name)
		error_exit(ERR_EMPTY_PATH, 4);
	i = 0;
	while(f_name[i])
		i++;
	while(f_name[i] != '.' && i >= -1)
		i--;
	if (i == -1 || !ft_strcmp((f_name + 1), ".fdf"))
		error_exit(ERR_INVALID_FILE_FORMAT, 5);
	return (1);
}

char	*read_map(int fd)
{
	char	*str;
	char	*str_tmp;

	str = ft_strdup("");
	str_tmp = get_next_line(fd);
	if (!str_tmp)
		error_exit(ERR_GNL, 7);
	while (1)
	{
		if (str_tmp != 0)
			str = ft_strjoin(str, str_tmp); //0 0 0 1 0 2 0 \n 0 0 1 0 2 0 \n
		else
			break;
		free (str_tmp);
		str_tmp = get_next_line(fd);
	}
	close (fd);
	return (str);
}

int	get_rows(const char *str)
{
	int		rows;
	int		i;

	rows = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i + 1] == 0)
			rows++;
		i++;
	}
	ft_printf("[Log]: Rows file: %d\n", rows);
	return (rows);
}

int	get_columns(const char *str)
{
	int		columns;
	int		i;

	i = 0;
	columns = 0;
	while(str[i] != '\n')
	{
		if (str[i] != ' ' && i == 0)
			columns++;
		else if(str[i - 1] == ' ' && str[i] != ' ')
			columns++;
		i++;
	}
	ft_printf("[Log]: Columns file: %d\n", columns);
	return (columns);
}

int	get_mult(t_map *map)
{
	int		mult;

	mult = 0;
	if (map->columns > map->rows)
		mult = map->columns / 800;
	else
		mult = map->rows / 800;
	
	if (mult < 2)
		mult = 2;
	ft_printf("[Log]: Multiplier value: %d\n", mult);
	return (mult);
}

void	get_origin(t_map *map)
{
	int		window_x;
	int		window_y;
	int		img_x;
	int		img_y;

	window_x = WIN_WIDTH / 2;
	window_y = WIN_HEIGHT / 2;
	img_x = ((map->rows - 1) / 2) * map->mult;
	img_y = ((map->columns - 1) / 2) * map->mult;
	map->origin_x = map->origin_x + (window_x - img_x);
	map->origin_y = map->origin_y + (window_y - img_y);
	ft_printf("[Log]: Origin_X value: %d\n", map->origin_x);
	ft_printf("[Log]: Origin_Y value: %d\n", map->origin_y);
}

void	get_metadata(t_map *map, const char *str)
{
	map->rows = get_rows(str);
	map->columns = get_columns(str);
	map->size = map->rows * map->columns; //number of points on the map
	map->mult = get_mult(map); //number of segment size
	map->origin_x = 0;
	map->origin_y = 0;
	get_origin(map);
	ft_printf("[Log]: Size/Dots value: %d\n", map->size);
}

char	*init_map(t_mlx *mlx, const char *f_name)
{
	int		fd;
	char	*str;

	fd = open(f_name, O_RDONLY);
	if (!fd)
		return (0);
	str = read_map(fd);
	get_metadata(&mlx->data_map, str);
	return (str);
}

void list_points(t_mlx *mlx)
{
	int i;

	for (i = 0; i < mlx->data_map.size; i++)
	{
		ft_printf("[Log]: Point %d: X = %d, Y = %d, Z = %d\n", i, mlx->pts[i].x, mlx->pts[i].y, mlx->pts[i].z);
	}
}


t_mlx	*init_fdf(const char *f_name)
{
	t_mlx	*mlx;
	char	*str;

	mlx = (t_mlx *)malloc(1 * sizeof(t_mlx));
	if (!mlx)
		error_exit(ERR_MALLOC, 2);
	if (!check_path(f_name))
		error_exit(ERR_INVALID_PATH, 3);
	str = init_map(mlx, f_name);
	if (!str)
		error_exit(ERR_INVALID_PATH, 6);
	mlx->pts = (t_point *)malloc(sizeof(t_point) * mlx->data_map.size);
	if (!mlx->pts)
		error_exit(ERR_MALLOC, 8);
	set_pts(mlx, str);
	list_points(mlx);
	return (mlx);
}