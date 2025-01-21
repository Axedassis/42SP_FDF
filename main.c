/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:20:54 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/20 22:42:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int main(int argc, char **argv)
{
	char	*file_name;
	t_mlx	*mlx;
	
	if (argc != 2)
		error_exit(ERR_AMOUNT_ARGS, 1);
	file_name = argv[1];
	mlx = init_fdf(file_name);
	if (init_mlx(mlx) == -1)
		error_exit (ERR_MLX_INIT, 10);
	render_map(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}