/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:23:03 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/20 21:50:01 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	getcenter(t_mlx *mlx, int *centerX, int *centerY)
{
	int	halfx;
	int	halfy;

	halfx = (mlx->pts[mlx->data_map.size - 1].x - mlx->pts[0].x) / 2;
	halfy = (mlx->pts[mlx->data_map.size - 1].y - mlx->pts[0].y) / 2;
	*centerX = mlx->pts[0].x + halfx;
	*centerY = mlx->pts[0].y + halfy;
}

static double	getrad(float deltaX, float deltaY)
{
	double	rad;

	if (deltaY == 0 && deltaX >= 0)
		rad = 0;
	else if (deltaY > 0 && deltaX > 0)
		rad = atan(deltaY / deltaX);
	else if (deltaY > 0 && deltaX == 0)
		rad = 1.5708;
	else if (deltaY > 0 && deltaX < 0)
		rad = 3.1415 + atan(deltaY / deltaX);
	else if (deltaY == 0 && deltaX < 0)
		rad = 3.1415;
	else if (deltaY < 0 && deltaX < 0)
		rad = 3.1415 + atan(deltaY / deltaX);
	else if (deltaY < 0 && deltaX == 0)
		rad = 4.7124;
	else if (deltaY < 0 && deltaX > 0)
		rad = 6.2832 + atan(deltaY / deltaX);
	return (rad);
}

t_mlx	*transform_pts(t_mlx *mlx, float rad1, float rad2)
{
	t_translate		translate;
	int			i;

	getcenter(mlx, &translate.centerx, &translate.centery);
	i = -1;
	while (i++, i < mlx->data_map.size)
	{
		translate.deltax = mlx->pts[i].x - translate.centerx;
		translate.deltay = (mlx->pts[i].y - translate.centery) * -1;
		translate.tan = sqrt((translate.deltax * translate.deltax) + (translate.deltay * translate.deltay));
		translate.rad = getrad(translate.deltax, translate.deltay) + rad1;
		translate.deltax = translate.tan * cos(translate.rad);
		translate.deltay = translate.tan * sin(translate.rad);
		mlx->pts[i].x = translate.deltax + translate.centerx;
		mlx->pts[i].y = translate.centery - (translate.deltay * cos(rad2));
		mlx->pts[i].y -= (mlx->pts[i].z * sin(rad2) * mlx->data_map.mult / 8);
	}
	return (mlx);
}