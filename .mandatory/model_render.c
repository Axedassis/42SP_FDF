/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:07 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/01/31 13:05:25 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_line *line)
{
	t_pts	new_start;
	t_pts	new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_start.y = (line->start.x + line->start.y) * sin(ANG_30)
		- line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_end.y = (line->end.x + line->end.y) * sin(ANG_30)
		- line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}
