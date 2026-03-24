/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:46:27 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/24 00:45:25 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

// GAME
# define TITLE "Cub3d"

// MLX
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define WINDOW_CLOSE 17
# define WINDOW_CLOSE_MASK 1l << 17

# define KEY_PRESS 2
# define KEY_PRESS_MASK 1L << 0

# define KEY_RELEASE 3
# define KEY_RELEASE_MASK 1L << 1

// TEXTURES AND COLORS
# define TEXTURE_COUNT 4
# define COLOR_COUNT 2

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define CEILING 0
# define FLOOR 1

// PARSER
# define VALID_MAP_CHARS "01 NSEW\n"
# define PLAYER_CHARS "NSEW"
# define TYPE_COUNT TEXTURE_COUNT + COLOR_COUNT
# define NO_COLOR 0xFFFFFFFF

// PLAYER
# define PLAYER_INFO_COUNT 6

# define POS_X 0
# define POS_Y 1

# define DIR_X 2
# define DIR_Y 3

# define FOV_X 4
# define FOV_Y 5

// KEYS
# define ESC 27

#endif