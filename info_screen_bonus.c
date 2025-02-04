/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:47:40 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/04 01:24:58 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	print_menu(t_mlx *mmlx)
{
	int		y;
	int		col;
	void	*mlx;
	void	*win;

	y = 0;
	col = 0xFFFFFF;
	mlx = mmlx->mlx;
	win = mmlx->win;
	mlx_string_put(mlx, win, 50, y += 35, col, "Press 'ESC' to close");
	mlx_string_put(mlx, win, 50, y += 35, col, "Zoom: press '-' or '+'");
	mlx_string_put(mlx, win, 50, y += 20, col, "Move: press arrow keys");
	mlx_string_put(mlx, win, 50, y += 20, col, "Rotate X: press 'S' or 'W'");
	mlx_string_put(mlx, win, 50, y += 20, col, "Rotate Y: press 'Q' or 'E'");
	mlx_string_put(mlx, win, 50, y += 20, col, "Rotate Z: press 'A' or 'D'");
	mlx_string_put(mlx, win, 50, y += 20, col, "Scale Z: press 'Z' or 'X'");
	mlx_string_put(mlx, win, 50, y += 20, col, "(Z Scale limited to 100%)");
	mlx_string_put(mlx, win, 50, y += 35, col, "To change projection view:");
	mlx_string_put(mlx, win, 50, y += 35, col, "Isometric: press 'I'");
	mlx_string_put(mlx, win, 50, y += 35, col, "Side Parallel: press 'P'");
	mlx_string_put(mlx, win, 50, y += 35, col, "Top view: press 'T'");
	mlx_string_put(mlx, win, 50, y += 35, col, "Colors: press 'SPACE'");
	mlx_string_put(mlx, win, 50, y += 35, col, "Reset view: press 'R'");
}

void	key_project(int keycode, t_mlx *mlx)
{
	if (keycode == XK_i)
		mlx->cam.project = 1;
	else if (keycode == XK_p)
		mlx->cam.project = 2;
	else if (keycode == XK_t)
		mlx->cam.project = 3;
}