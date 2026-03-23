/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:30:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/23 15:31:41 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "mlx.h"

int		destroy_game(t_game *game);
t_bool	init_mlx_display(t_mlx	*mlx, char **path);

//render
void	put_pixel(t_mlx *mlx, int x, int y, int color);
void	draw_floor_and_sky(t_mlx *mlx);
void    raycast(t_game *game);


#endif