/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:25:32 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/23 19:13:45 by brfialho         ###   ########.fr       */
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

//TESTE
char *map[] = {
    "111111",
    "100001",
    "100001",
    "100001",
    "111111",
    NULL
};

void print_wall(t_mlx *mlx, int x, double distance)
{
    int wallHeight;
    int wallStart;
    int wallEnd;
    int y;

    wallHeight = (int)(WIN_HEIGHT / distance);

    wallStart = (WIN_HEIGHT / 2) - (wallHeight / 2);
    wallEnd   = (WIN_HEIGHT / 2) + (wallHeight / 2);

    if (wallStart < 0)
        wallStart = 0;
    if (wallEnd >= WIN_HEIGHT)
        wallEnd = WIN_HEIGHT - 1;

    y = wallStart;
    while (y++ < wallEnd)
        put_pixel(mlx, x, y, 0x808080);
}

void raycast(t_game *game)
{
    double playerX = 2.0;
    double playerY = 2.0;

    double dirX = 1.0;
    double dirY = 0.0;

    double planeX = 0.0;
    double planeY = 0.66;

    int i;
    
    i = -1;
    while (++i < WIN_WIDTH)
    {
        double cameraX = 2 * i / (double)WIN_WIDTH - 1;

        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        double distance = 0.01;

        while (1)
        {
            distance += 0.01;

            int x = (int)(playerX + rayDirX * distance);
            int y = (int)(playerY + rayDirY * distance);

            if (y < 0 || x < 0 || map[y] == NULL || map[y][x] == '\0')
                break;

            if (map[y][x] == '1')
            {
                print_wall(&game->mlx, i, distance);
                break;
            }
        }
    }
}
