/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:24:11 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/27 20:04:23 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "math.h"


void	raycast(t_game *game)
{
	int		i;
	i = -1;
	while (++i < WIN_WIDTH)
	{
		double	camera_x = 2 * i / (double)WIN_WIDTH - 1;
		double	ray_dir_x = game->player[DIR_X] +  game->player[FOV_X] * camera_x;
		double	ray_dir_y = game->player[DIR_Y] + game->player[FOV_Y] * camera_x;
		int	map_x = (int)game->player[POS_X];
		int	map_y = (int)game->player[POS_Y];
		double	delta_dist_x = fabs(1.0 / ray_dir_x);
		double	delta_dist_y = fabs(1.0 / ray_dir_y);
		double	side_dist_x;
		double	side_dist_Y;

		if (ray_dir_x < 0)
			side_dist_x = (game->player[POS_X] - map_x) * delta_dist_x;
		else
			side_dist_x = (map_x + 1.0 - game->player[POS_X]) * delta_dist_x;
		if (ray_dir_y < 0)
			side_dist_Y = (game->player[POS_Y] - map_y) * delta_dist_y;
		else
			side_dist_Y = (map_y + 1.0 - game->player[POS_Y]) * delta_dist_y;
		int	step_x;
		int	step_y;

		if (ray_dir_x < 0)
			step_x = -1;
		else
			step_x = 1;
		if (ray_dir_y < 0)
			step_y = -1;
		else
			step_y = 1;
		int side;

		while (1)
		{
			if (side_dist_x < side_dist_Y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_Y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (((char **)game->map.tab)[map_y][map_x] == '1')
			{
				int texture;
				
				texture = get_texture(side, step_x, step_y);

				double wall_x;
				if (side == 0)
					wall_x = game->player[POS_Y] + (side_dist_x - delta_dist_x) * ray_dir_y;
				else
					wall_x = game->player[POS_X] + (side_dist_Y - delta_dist_y) * ray_dir_x;
				wall_x -= (int)wall_x;
				if (side == 0)
					print_wall(&game->mlx, side_dist_x - delta_dist_x, i, wall_x, texture);
				else
					print_wall(&game->mlx, side_dist_Y - delta_dist_y, i, wall_x, texture);
				break ;
			}
		}
	}
}
