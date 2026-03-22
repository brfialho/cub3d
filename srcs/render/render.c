/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:25:32 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/21 22:42:23 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void put_pixel(t_mlx *mlx, int x, int y, int color)
{
    char *dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void draw_floor_and_sky(t_mlx *mlx)
{
    int y;
    int x;

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
