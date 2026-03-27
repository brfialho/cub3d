/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:24:11 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/25 22:13:58 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "math.h"

// TESTE
char	*map[] = {
	"1111111111111111111111111111111111",
	"1000000000000000000000000000000001",
	"1000000000000000000000000000000001",
	"1000000000000000000000000000000001",
	"1111111111111111111111111111111111",
	NULL};

void	raycast(t_game *game)
{
	int	i;
	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	player_x = 2.5;
	player_y = 2.5;
	dir_x = 1.0;
	dir_y = 0.0;
	plane_x = 0.0;
	plane_y = 0.66;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		double camera_x = 2 * i / (double)WIN_WIDTH - 1;
		double	ray_dir_x = dir_x + plane_x * camera_x;
		double	ray_dir_y = dir_y + plane_y * camera_x;
		int	map_x = (int)player_x;
		int	map_y = (int)player_y;
		double	delta_dist_x = fabs(1.0 / ray_dir_x);
		double	delta_dist_y = fabs(1.0 / ray_dir_y);
		double	side_dist_x;
		double	side_dist_Y;

		if (ray_dir_x < 0)
			side_dist_x = (player_x - map_x) * delta_dist_x;
		else
			side_dist_x = (map_x + 1.0 - player_x) * delta_dist_x;
		if (ray_dir_y < 0)
			side_dist_Y = (player_y - map_y) * delta_dist_y;
		else
			side_dist_Y = (map_y + 1.0 - player_y) * delta_dist_y;
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
			if (map[map_y][map_x] == '1')
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
				double wall_x;
				if (side == 0)
					wall_x = player_y + (side_dist_x - delta_dist_x) * ray_dir_y;
				else
					wall_x = player_x + (side_dist_Y - delta_dist_y) * ray_dir_x;
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
