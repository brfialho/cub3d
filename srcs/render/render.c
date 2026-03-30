/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:25:32 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/29 21:08:24 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
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

static t_wall	init_wall(t_mlx *mlx, double distance,
		double wall_x, int texture)
{
	t_wall	wall;

	wall.height = (int)(WIN_HEIGHT / distance);
	wall.start = (WIN_HEIGHT - wall.height) / 2;
	wall.end = wall.start + wall.height;
	wall.tex_x = (int)(wall_x * mlx->tex_width[texture]);
	if (wall.tex_x < 0)
		wall.tex_x = 0;
	if (wall.tex_x >= mlx->tex_width[texture])
		wall.tex_x = mlx->tex_width[texture] - 1;
	return (wall);
}

void	print_wall(t_mlx *mlx, t_wall_data *data, int x)
{
	t_wall	wall;
	int		tex_y;
	int		tex_pixel;
	int		y;
	int		real_start;

	wall = init_wall(mlx, data->distance, data->wall_x, data->texture);
	real_start = wall.start;
	if (wall.start < 0)
		wall.start = 0;
	if (wall.end > WIN_HEIGHT - 1)
		wall.end = WIN_HEIGHT - 1;
	y = wall.start;
	while (y < wall.end)
	{
		tex_y = (y - real_start) * mlx->tex_height[data->texture] / wall.height;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= mlx->tex_height[data->texture])
			tex_y = mlx->tex_height[data->texture] - 1;
		tex_pixel = return_pixel(mlx, wall.tex_x, tex_y, data->texture);
		put_pixel(mlx, x, y, tex_pixel);
		y++;
	}
}
