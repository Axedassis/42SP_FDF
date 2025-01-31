/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:26:47 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/31 12:49:32 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*read_map(t_mlx *mlx, int fd);
static void		path_checker(t_mlx *mlx, const char *path_file);
static int		get_row_lenght(char *str);
static int		get_columns_heigth(char *str);

char	*init_map(t_mlx *mlx, const char *path_file)
{
	int		fd;
	char	*readed_map;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
	{
		free (mlx);
		error_exit("Invalid file path", 3);
	}
	path_checker(mlx, path_file);
	readed_map = read_map(mlx, fd);
	mlx->map.max_x = get_row_lenght(readed_map);
	mlx->map.max_y = get_columns_heigth(readed_map);
	mlx->map.max_z = 0;
	mlx->map.min_z = 0;
	return (readed_map);
}

static void	path_checker(t_mlx *mlx, const char *path_file)
{
	int		i;

	i = 0;
	while (path_file[i])
		i++;
	while (path_file[i] != '.' && i >= -1)
		i--;
	if (i == -1 || !ft_strcmp((path_file + 1), ".fdf"))
	{
		free(mlx);
		error_exit("Invalid file format", 4);
	}
}

static char	*read_map(t_mlx *mlx, int fd)
{
	char	*str;
	char	*str_tmp;
	char	*temp;

	str = ft_strdup("");
	str_tmp = get_next_line(fd);
	if (!str_tmp)
	{
		free (mlx);
		free(str);
		error_exit("Get next line error", 12);
	}
	while (str_tmp)
	{
		temp = str;
		str = ft_strjoin(str, str_tmp);
		free(temp);
		free(str_tmp);
		str_tmp = get_next_line(fd);
	}
	close(fd);
	return (str);
}

static int	get_row_lenght(char *str)
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
	return (rows);
}

static int	get_columns_heigth(char *str)
{
	int		columns;
	int		i;

	i = 0;
	columns = 0;
	while (str[i] != '\n')
	{
		if (str[i] != ' ' && i == 0)
			columns++;
		else if (str[i - 1] == ' ' && str[i] != ' ')
			columns++;
		i++;
	}
	return (columns);
}
