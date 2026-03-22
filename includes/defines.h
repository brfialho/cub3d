/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:46:27 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/21 22:51:45 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

// Game
# define TITLE "Cub3d"

// MLX
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define WINDOW_CLOSE 17
# define WINDOW_CLOSE_MASK 1l << 17

// TEXTURES
# define TEXTURE_COUNT 4
# define COLOUR_COUNT 2

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define CEILING 0
# define FLOOR 1

// Parser
# define VALID_MAP_CHARS "01\t NSEW\n"
# define TYPE_COUNT TEXTURE_COUNT + COLOUR_COUNT

#endif