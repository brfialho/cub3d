/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:24:11 by gbercaco          #+#    #+#             */
/*   Updated: 2026/03/29 20:54:53 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "math.h"
#include <stdio.h>

static void	draw_wall(t_ray *ray, t_game *game, int i)
{
	t_wall_data	data;
	double		perp_dist;

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
	perp_dist = data.distance * (ray->ray_dir_x * game->player[DIR_X]
			+ ray->ray_dir_y * game->player[DIR_Y]);
	data.distance = perp_dist;
	data.wall_x -= (int)data.wall_x;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		data.wall_x = 1.0 - data.wall_x;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		data.wall_x = 1.0 - data.wall_x;
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
