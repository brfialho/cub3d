/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:30:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 13:30:19 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "parsing.h"
# include "render.h"
# include "mlx.h"
# include <sys/time.h>
# include <math.h>

t_bool	init_game(t_game *game);
int		destroy_game(t_game *game);
void	raycast(t_game *game);
void	move_player(t_game *game);

#endif