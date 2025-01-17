/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:54:55 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/17 20:34:59 by lsilva-x         ###   ########.fr       */
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
		error_exit(ERR_EMPTY_PATH, 4)
	i = 0;
	while(f_name[i])
		i++;
	while(f_name[i] != '.' && i >= -1)
		i--;
	if (i == -1 || !ft_strcmp((f_name + 1), ".fdf"))
		error_exit(ERR_INVALID_FILE_FORMAT, 5);
	return (0)
}

int	set_dimensions(t_map *map, const char *f_name)
{
	int		fd;
	int		width;
	int		heigth;

	fd = open(f_name, O_RDONLY)
	if (!fd)
		return (0);
	
}

t_mlx	*init_fdf(const char *f_name)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(1 * sizeof(t_mlx));
	if (!mlx)
		error_exit(ERR_MALLOC, 2);
	if (!check_path(f_name))
		error_exit(ERR_INVALID_PATH, 3);
	if (!set_dimensions(mlx->map, f_name))
		error_exit(ERR_INVALID_PATH, 6);
		
	return (mlx);
}