/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:28:14 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 21:12:56 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft/includes/libft.h"
# include "macros.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>

void	error_exit(const char *msg, int code);
t_mlx	*init_fdf(const char *path_file);
void	free_pts(t_mlx *mlx);
char	*init_map(t_mlx *mlx, const char *path_file);
void	init_pts(t_map *map, char *readed_map);
void	init_malloc_pts(t_mlx *mlx, char *readed_map);
void	init_mlx(t_mlx *mlx);

#endif