/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_sky.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:25:32 by gbercaco          #+#    #+#             */
/*   Updated: 2026/04/06 17:06:57 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_floor_and_sky(t_mlx *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			put_pixel(mlx, x, y, mlx->colors[CEILING]);
	}
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			put_pixel(mlx, x, y, mlx->colors[FLOOR]);
		y++;
	}
}
