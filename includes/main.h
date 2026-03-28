/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:30:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/28 03:10:45 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "parsing.h"
# include "mlx.h"
# include <sys/time.h>
# include <math.h>

int		destroy_game(t_game *game);
t_bool	init_game(t_game *game);

//render
void	put_pixel(t_mlx *mlx, int x, int y, int color);
int		return_pixel(t_mlx *mlx, int x, int y, int texuture);
void	draw_floor_and_sky(t_mlx *mlx);
void	print_wall(t_mlx *mlx, double distance, int x, double wallX, int texture);
void	raycast(t_game *game);
int		get_texture(int side, int step_x, int step_y);
void	move_player(t_game *game);

#endif