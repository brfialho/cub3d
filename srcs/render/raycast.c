/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:24:11 by gbercaco          #+#    #+#             */
/*   Updated: 2026/04/06 13:10:33 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	dda_step(t_ray *ray);
static void	init_ray(t_ray *ray, t_game *game, int i);
static void	set_steps(t_ray *ray);
static void	set_dist(t_ray *ray, t_game *game);

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

static void	dda_step(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

static void	init_ray(t_ray *ray, t_game *game, int i)
{
	double	camera_x;

	camera_x = 2 * i / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = game->player[DIR_X] + game->player[FOV_X] * camera_x;
	ray->ray_dir_y = game->player[DIR_Y] + game->player[FOV_Y] * camera_x;
	ray->map_x = (int)game->player[POS_X];
	ray->map_y = (int)game->player[POS_Y];
	set_dist(ray, game);
	set_steps(ray);
}

static void	set_dist(t_ray *ray, t_game *game)
{
	ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
		ray->side_dist_x = (game->player[POS_X] - ray->map_x)
			* ray->delta_dist_x;
	else
		ray->side_dist_x = (ray->map_x + 1.0 - game->player[POS_X])
			* ray->delta_dist_x;
	if (ray->ray_dir_y < 0)
		ray->side_dist_y = (game->player[POS_Y] - ray->map_y)
			* ray->delta_dist_y;
	else
		ray->side_dist_y = (ray->map_y + 1.0 - game->player[POS_Y])
			* ray->delta_dist_y;
}

static void	set_steps(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}
