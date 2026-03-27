/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:25:32 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/25 22:14:37 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	return_pixel(t_mlx *mlx, int x, int y, int texuture)
{
	char	*dst;

	dst = mlx->tex_addr[texuture] + (y * mlx->tex_line[texuture]
			+ x * (mlx->tex_bpp[texuture] / 8));
	return (*(unsigned int *)dst);
}

void	draw_floor_and_sky(t_mlx *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			put_pixel(mlx, x, y, 0xADD8E6);
	}
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			put_pixel(mlx, x, y, 0x8B4513);
		y++;
	}
}

void	print_wall(t_mlx *mlx, double distance, int x,
							double wall_x, int texture)
							{
	int	y;
	int	colum_height;
	int	start_colum;
	int	end_colum;
	int	text_x;
	int	tex_y;
	int	tex_pixel;

	colum_height = (int)(WIN_HEIGHT / distance);
	start_colum = (WIN_HEIGHT - colum_height) / 2;
	end_colum = start_colum + colum_height;
	text_x = wall_x * mlx->tex_width[texture];
	if (start_colum < 0)
		start_colum = 0;
	if (end_colum > WIN_HEIGHT - 1)
		end_colum = WIN_HEIGHT - 1;
	y = start_colum;
	while (y < end_colum)
	{
		tex_y = (y - start_colum) * mlx->tex_height[texture] / colum_height;
		tex_pixel = return_pixel(mlx, text_x, tex_y, texture);
		put_pixel(mlx, x, y, tex_pixel);
		y++;
	}
}
