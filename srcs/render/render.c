/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:25:32 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/24 23:18:10 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "math.h"

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

        int mapX = (int)playerX;
        int mapY = (int)playerY;

        double deltaDistX = fabs(1.0 / rayDirX);
        double deltaDistY = fabs(1.0 / rayDirY);

        double sideDistX;
        double sideDistY;

        if (rayDirX < 0)
            sideDistX = (playerX - mapX) * deltaDistX;
        else
            sideDistX = (mapX + 1.0 - playerX) * deltaDistX;

        if (rayDirY < 0)
            sideDistY = (playerY - mapY) * deltaDistY;
        else
            sideDistY = (mapY + 1.0 - playerY) * deltaDistY;

        int stepX;
        int stepY;

        if (rayDirX < 0)
            stepX = -1;
        else
            stepX = 1;

        if (rayDirY < 0)
            stepY = -1;
        else
            stepY = 1;

        int side;

        while (1)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            if (map[mapY][mapX] == '1')
            {
                int texture;
                if (side == 0)
                {
                    if (stepX > 0)
                        texture = WEST;
                    else
                        texture = EAST;
                }
                else
                {
                    if (stepY > 0)
                        texture = NORTH;
                    else
                        texture = SOUTH;
                }

                double wallX;
                if (side == 0)
                    wallX = playerY + (sideDistX - deltaDistX) * rayDirY;
                else
                    wallX = playerX + (sideDistY - deltaDistY) * rayDirX;
                wallX -= (int)wallX;

                if (side == 0)
                    print_wall(&game->mlx, i, sideDistX - deltaDistX, texture, wallX);
                else
                    print_wall(&game->mlx, i, sideDistY - deltaDistY, texture, wallX);
                break;
            }
        }
    }
}
