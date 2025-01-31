/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:38:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 21:03:32 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

#define WIN_WIDTH 900
#define WIN_HEIGHT 900

#define IMG_WIDTH WIN_WIDTH
#define IMG_HEIGHT WIN_HEIGHT

typedef struct	s_pt
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_pts;

typedef struct	s_map
{
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
	t_pts	**pts;
}	t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_map	map;
	// t_cam	cam;
	t_data	img;
}	t_mlx;

#endif