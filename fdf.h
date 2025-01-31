/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:28:14 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 23:44:03 by lsilva-x         ###   ########.fr       */
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
void	init_cam(t_mlx *mlx);
void	clear_buffer(t_data *img);
void	init_render(t_mlx *mlx);
void	bresenhams(t_mlx *mlx, t_line *line);
void	close_window(t_mlx *mlx);
void	pixel_to_image(t_data *image, float x, float y, int color);


#endif