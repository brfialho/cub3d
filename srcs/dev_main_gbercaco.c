/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_main_gbercaco.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:31:16 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/19 22:42:44 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include <stdio.h>

char *map[] = {
    "111111",
    "100001",
    "100001",
    "100001",
    "111111",
    NULL
};

void print_wall(double distance)
{
    int height = (int)(10 / distance);

    for (int i = 0; i < height; i++)
        printf("#");
    printf("\n");
}

int main()
{
    double playerX = 2.0;
    double playerY = 2.0;

    // direção do player (olhando pra direita)
    double dirX = 1.0;
    double dirY = 0.0;

    // plano da câmera (perpendicular)
    double planeX = 0.0;
    double planeY = 0.66;

    int screenWidth = 20;

    for (int i = 0; i < screenWidth; i++)
    {
        // valor de -1 até 1
        double cameraX = 2 * i / (double)screenWidth - 1;

        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        double distance = 0.0;

        while (1)
        {
            distance += 0.1;

            int x = (int)(playerX + rayDirX * distance);
            int y = (int)(playerY + rayDirY * distance);

            // proteção pra não dar segfault
            if (y < 0 || x < 0 || map[y] == NULL || map[y][x] == '\0')
                break;

            if (map[y][x] == '1')
            {
                print_wall(distance);
                break;
            }
        }
    }

    return 0;
}