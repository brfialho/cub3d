/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:06:12 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 13:28:58 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "structs.h"
# include "defines.h"
# include <math.h>

typedef struct s_wall_data
{
    double  distance;
    double  wall_x;
    int     texture;
}   t_wall_data;

typedef struct s_wall
{
    int	height;
    int	start;
    int	end;
    int	tex_x;
}   t_wall;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

void	raycast(t_game *game);
void	draw_wall(t_ray *ray, t_game *game, int i);
void	draw_floor_and_sky(t_mlx *mlx);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
int		return_pixel(t_mlx *mlx, int x, int y, int texuture);

#endif