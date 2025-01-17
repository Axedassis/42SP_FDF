/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:54:55 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/17 17:51:42 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./macros.h"

# ifndef FDF_H
#define FDF_H


/*
 _ _ _                     
| (_) |                    
| |_| |__  _ __ __ _ _   _ 
| | | '_ \| '__/ _` | | | |
| | | |_) | | | (_| | |_| |
|_|_|_.__/|_|  \__,_|\__, |
                      __/ |
                     |___/ 
*/

#include "./libft/includes/libft.h"
#include "./minilibx-linux/mlx.h"
//XK_@
#include <X11/keysym.h>
//strerror
#include <string.h>
//open, close, read, write
#include <unistd.h>
//math functions
#include <math.h>
//malloc, free, exit
#include <stdlib.h>
// perror
#include <stdio.h>

/*
  __                  _   _                 
 / _|                | | (_)                
| |_ _   _ _ __   ___| |_ _  ___  _ __  ___ 
|  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| | | |_| | | | | (__| |_| | (_) | | | \__ \
|_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
                                            
*/
int	error_exit(const char *msg, int code);
t_mlx	*init_fdf(const char *f_name);
int	check_path(const char *f_name);

# endif
