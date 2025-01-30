/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:38:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/30 18:39:36 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

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


typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_map	map;
	// t_cam	cam;
	// t_data	img;
}	t_mlx;

#endif