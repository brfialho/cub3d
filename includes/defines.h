/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:46:27 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 16:33:44 by brfialho         ###   ########.fr       */
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
# define KEY_PRESS 2
# define KEY_RELEASE 3

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
# define ERROR_PARSER 1
# define ERROR_MAP 2
# define ERROR_MULTI_ELEMT 10
# define ERROR_INLINE_MULTI_ELEMT 3
# define ERROR_REPEAT_ELEMENT 11
# define ERROR_IDENTIFIER 4
# define ERROR_C_MULTI 5
# define ERROR_C_NUM 6
# define ERROR_C_VALUE 7

# define ERROR_OPEN_BORDER 8
# define ERROR_PLAYER_COUNT 9

# define VALID_MAP_CHARS "01 NSEW\n"
# define PLAYER_CHARS "NSEW"
// Type count is TEXTURE_COUNT + COLOR_COUNT
# define TYPE_COUNT 4 + 2
# define NO_COLOR 0xFFFFFFFF

// PLAYER
# define MOVE_SPEED 0.05
# define TURN_SPEED 0.025
# define MAX_FOV 0.66
# define PLAYER_INFO_COUNT 6

# define POS_X 0
# define POS_Y 1

# define DIR_X 2
# define DIR_Y 3

# define FOV_X 4
# define FOV_Y 5

// KEYS
# define ESC 27
# define LEFT_ARROW 81
# define RIGHT_ARROW 83

// TIME
# define ONE_SIXTIETH_OF_SEC 16666

#endif