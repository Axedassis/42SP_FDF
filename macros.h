/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:46:48 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/17 20:43:30 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MACROS_H
#define MACROS_H

#include "./fdf.h"

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
	
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}	t_mlx;

#endif