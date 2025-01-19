/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:46:48 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/18 23:10:39 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MACROS_H
#define MACROS_H

/*
                                       _      
                                      | |     
  ___ _ __ _ __ ___  _ __ ___ ___   __| | ___ 
 / _ \ '__| '__/ _ \| '__/ __/ _ \ / _` |/ _ \
|  __/ |  | | | (_) | | | (_| (_) | (_| |  __/
 \___|_|  |_|  \___/|_|  \___\___/ \__,_|\___|
                                              
*/
#define ERR_AMOUNT_ARGS "[Error]: Invalid number of arguments"
#define ERR_MALLOC "[Error]: Memory allocation failure"
#define ERR_INVALID_PATH "[Error]: The provided path is invalid"
#define ERR_EMPTY_PATH "[Error]: The provided path is empty"
#define ERR_INVALID_FILE_FORMAT "[Error]: The provided file format is invalid"
#define ERR_GNL "[Error]: GNL had an error"

/*
     _                   _   
    | |                 | |  
 ___| |_ _ __ _   _  ___| |_ 
/ __| __| '__| | | |/ __| __|
\__ \ |_| |  | |_| | (__| |_ 
|___/\__|_|   \__,_|\___|\__|
                             
                             
*/

typedef struct s_img
{
	void	*img;
	char	*buffer;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		size;
	int		rows;
	int		columns;
	int		mult;
	int		origin_x;
	int		origin_y;
}	t_map;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	data_map;
	t_point	*pts;
}	t_mlx;

#endif