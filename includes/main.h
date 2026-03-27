/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:30:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/27 18:57:22 by gbercaco         ###   ########.fr       */
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

int		destroy_game(t_game *game);
t_bool	init_game(t_game *game);

//render
void	put_pixel(t_mlx *mlx, int x, int y, int color);
int     return_pixel(t_mlx *mlx, int x, int y, int texuture);
void	draw_floor_and_sky(t_mlx *mlx);
void    print_wall(t_mlx *mlx , double distance, int x, double wallX, int texture);
void    raycast(t_game *game);


#endif