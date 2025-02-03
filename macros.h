/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:38:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/03 15:17:33 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define WIN_WIDTH 1400
# define WIN_HEIGHT 900

# define ANG_30 0.52359877
# define ANG_1	0.01745329
# define ANG_45 0.78539816

# define IMG_WIDTH WIN_WIDTH
# define IMG_HEIGHT WIN_HEIGHT

# define COL_GREEN 0xF5004F
# define COL_BLUE 0x2707FF
# define COL_DEFAULT 0xFFFFFF

# define MSK_RED 0xFF0000
# define MSK_GREEN 0x00FF00
# define MSK_BLUE 0x0000FF


typedef struct s_color
{
	int	start_color;
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_color;
	int	end_r;
	int	end_g;
	int	end_b;
	int	delta_r;
	int	delta_g;
	int	delta_b;
}	t_color;

typedef struct s_pt
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_pts;

typedef struct s_map
{
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
	int		h_col;
	t_pts	**pts;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_cam
{
	int		mv_x;
	int		mv_y;
	float	scale_factory;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_cam	cam;
	t_data	img;
}	t_mlx;

typedef struct s_line
{
	t_pts	start;
	t_pts	end;
	float	transform_z;
}	t_line;

typedef struct s_delta {
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	t_color	*color;

} t_delta;


#endif
