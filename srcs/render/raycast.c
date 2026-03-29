/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:24:11 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/28 19:48:29 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "math.h"

static void	draw_wall(t_ray *ray, t_game *game, int i)
{
	t_wall_data	data;

	data.texture = get_texture(ray->side, ray->step_x, ray->step_y);
	if (ray->side == 0)
	{
		data.distance = ray->side_dist_x - ray->delta_dist_x;
		data.wall_x = game->player[POS_Y] + data.distance * ray->ray_dir_y;
	}
	else
	{
		data.distance = ray->side_dist_y - ray->delta_dist_y;
		data.wall_x = game->player[POS_X] + data.distance * ray->ray_dir_x;
	}
	data.wall_x -= (int)data.wall_x;
	print_wall(&game->mlx, &data, i);
}

void	raycast(t_game *game)
{
	t_ray	ray;
	int		i;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		init_ray(&ray, game, i);
		while (1)
		{
			dda_step(&ray);
			if (((char **)game->map.tab)[ray.map_y][ray.map_x] == '1')
			{
				draw_wall(&ray, game, i);
				break ;
			}
		}
	}
}
