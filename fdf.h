/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:28:14 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/02 23:47:23 by lsilva-x         ###   ########.fr       */
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

void		error_exit(const char *msg, int code);
t_mlx		*init_fdf(const char *path_file);
void		free_pts(t_mlx *mlx);
char		*init_map(t_mlx *mlx, const char *path_file);
void		init_pts(t_map *map, char *readed_map);
void		init_malloc_pts(t_mlx *mlx, char *readed_map);
void		init_mlx(t_mlx *mlx);
void		init_cam(t_mlx *mlx);
void		clear_buffer(t_data *img);
void		init_render(t_mlx *mlx);
void		bresenhams(t_mlx *mlx, t_line *line);
int			close_window(t_mlx *mlx);
void		pixel_to_image(t_data *image, float x, float y, int color);
void		isometric(t_line *line);
void		parse_map(t_map *map, char *readed_map);
void		set_color(char **str, t_pts *ptr, t_map *map);
void		set_pt(char **str, int origin_x, int origin_y, t_map *map);
void		apply_color(t_mlx *mlx, t_pts *pts);
t_color		*init_pallet(int col_start, int col_end);
int			get_color(t_color *color, int crr_val, int max_val);
void		set_to_null(t_mlx *mlx);
float	get_scale(t_mlx *mlx);
#endif