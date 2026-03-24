/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:30:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/24 00:47:24 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "parsing.h"
# include "mlx.h"
# include <sys/stat.h>
# include <sys/time.h>
# include <fcntl.h>

int		destroy_game(t_game *game);
void	init_game(t_game *game);
t_bool	init_mlx_display(t_mlx	*mlx, char **path);

//render
void	put_pixel(t_mlx *mlx, int x, int y, int color);
void	draw_floor_and_sky(t_mlx *mlx);
void    raycast(t_game *game);


#endif