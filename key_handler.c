/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:03:32 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/03 23:45:24 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_scale(int keycode, t_mlx *mlx)
{
	if (keycode == XK_equal)
		mlx->cam.scale_factory += 0.5;
	else if (keycode == XK_minus)
		mlx->cam.scale_factory -= 0.5;
	else if (keycode == XK_r)
		mlx->cam.scale_factory = fmin((WIN_WIDTH / mlx->map.max_x),
				(WIN_HEIGHT / mlx->map.max_y));
}

static void	key_translate(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Right)
		mlx->cam.mv_x += 5;
	else if (keycode == XK_Left)
		mlx->cam.mv_x -= 5;
	else if (keycode == XK_Down)
		mlx->cam.mv_y += 5;
	else if (keycode == XK_Up)
		mlx->cam.mv_y -= 5;
}

static void	key_rotate(int keycode, t_mlx *mlx)
{
	double	step;

	step = 2 * ANG_1;
	if (keycode == XK_s)
		mlx->cam.alpha -= step;
	else if (keycode == XK_w)
		mlx->cam.alpha += step;
	else if (keycode == XK_a)
		mlx->cam.gamma -= step;
	else if (keycode == XK_d)
		mlx->cam.gamma += step;
	else if (keycode == XK_q)
		mlx->cam.beta -= step;
	else if (keycode == XK_e)
		mlx->cam.beta += step;
}

static void	key_scale_z(int keycode, t_mlx *mlx)
{
	if (keycode == XK_z && mlx->cam.scale_factory_z > -1)
		mlx->cam.scale_factory_z -= 0.08;
	else if (keycode == XK_x && mlx->cam.scale_factory_z < 1)
		mlx->cam.scale_factory_z += 0.08;
	else if (keycode == XK_space)
		mlx->map.h_col *= -1;
}

int	key_hook(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		close_window(mlx);
	if (keysym == XK_equal || keysym == XK_minus || keysym == XK_r)
		key_scale(keysym, mlx);
	if (keysym == XK_Left || keysym == XK_Right
		|| keysym == XK_Up || keysym == XK_Down)
		key_translate(keysym, mlx);
	if (keysym == XK_d || keysym == XK_s || keysym == XK_a
		|| keysym == XK_w || keysym == XK_q || keysym == XK_e)
		key_rotate(keysym, mlx);
	if (keysym == XK_z || keysym == XK_x || keysym == XK_space)
		key_scale_z(keysym, mlx);
	init_render(mlx);
	return (0);
}
