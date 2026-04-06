/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:52:48 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 13:24:58 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	get_texture(int side, int step_x, int step_y);
static void	print_wall(t_mlx *mlx, t_wall_data *data, int x);
static t_wall	init_wall(t_mlx *mlx, double distance,	
	double wall_x, int texture);

void	draw_wall(t_ray *ray, t_game *game, int i)
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

static void	print_wall(t_mlx *mlx, t_wall_data *data, int x)
{
	t_wall	wall;
	int		tex_y;
	int		tex_pixel;
	int		y;
	int		real_start;

	wall = init_wall(mlx, data->distance, data->wall_x, data->texture);
	real_start = wall.start;
	if (wall.start < 0)
		wall.start = 0;
	if (wall.end > WIN_HEIGHT - 1)
		wall.end = WIN_HEIGHT - 1;
	y = wall.start;
	while (y < wall.end)
	{
		tex_y = (y - real_start) * mlx->tex_data.height[data->texture]
				/ wall.height;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= mlx->tex_data.height[data->texture])
			tex_y = mlx->tex_data.height[data->texture] - 1;
		tex_pixel = return_pixel(mlx, wall.tex_x, tex_y, data->texture);
		put_pixel(mlx, x, y, tex_pixel);
		y++;
	}
}

static int	get_texture(int side, int step_x, int step_y)
{
	int	texture;

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
	return (texture);
}

static t_wall	init_wall(t_mlx *mlx, double distance,
		double wall_x, int texture)
{
	t_wall	wall;

	wall.height = (int)(WIN_HEIGHT / distance);
	wall.start = (WIN_HEIGHT - wall.height) / 2;
	wall.end = wall.start + wall.height;
	wall.tex_x = (int)(wall_x * mlx->tex_data.width[texture]);
	if (wall.tex_x < 0)
		wall.tex_x = 0;
	if (wall.tex_x >= mlx->tex_data.width[texture])
		wall.tex_x = mlx->tex_data.width[texture] - 1;
	return (wall);
}

