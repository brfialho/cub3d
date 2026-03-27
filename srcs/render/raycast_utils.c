/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:24:08 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/27 20:01:11 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_texture(int side, int step_x, int step_y)
{
    int texture;
    if (side == 0)
    {
        if (step_x > 0)
            texture = WEST;
        else
            texture = EAST;
    }
    else
    {
        if (step_y > 0)
            texture = NORTH;
        else
            texture = SOUTH;
    }
    return texture;
}
