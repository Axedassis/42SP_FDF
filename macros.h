/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:46:48 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/17 16:54:21 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

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
	t_line	*line;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

#endif