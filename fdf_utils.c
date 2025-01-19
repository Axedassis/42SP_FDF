/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:54:55 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/18 23:52:30 by lsilva-x         ###   ########.fr       */
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

	str_tmp = get_next_line(fd);
	if (!str_tmp)
		error_exit(ERR_GNL, 7);
	while (1)
	{
		if (str_tmp != 0)
			str = ft_strjoin(str, str_tmp);
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

void	get_metadata(t_map *map, const char *str)
{
	map->rows = get_rows(str);
	map->columns = get_columns(str);
	
}

int	init_map(t_mlx *mlx, const char *f_name)
{
	int		fd;
	char	*str;

	fd = open(f_name, O_RDONLY);
	if (!fd)
		return (0);
	str = read_map(fd);
	get_metadata(&mlx->data_map, str);
}

t_mlx	*init_fdf(const char *f_name)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(1 * sizeof(t_mlx));
	if (!mlx)
		error_exit(ERR_MALLOC, 2);
	if (!check_path(f_name))
		error_exit(ERR_INVALID_PATH, 3);
	if (!init_map(mlx, f_name))
		error_exit(ERR_INVALID_PATH, 6);
		
	return (mlx);
}