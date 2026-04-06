/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:06:12 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 13:11:54 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "structs.h"
# include "defines.h"
# include <math.h>

void	raycast(t_game *game);
void	draw_wall(t_ray *ray, t_game *game, int i);
void	draw_floor_and_sky(t_mlx *mlx);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
int		return_pixel(t_mlx *mlx, int x, int y, int texuture);

#endif