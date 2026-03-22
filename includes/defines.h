/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:46:27 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 06:43:05 by brfialho         ###   ########.fr       */
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

// TEXTURES
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
# define TYPE_COUNT TEXTURE_COUNT + COLOR_COUNT
# define NO_COLOR 0xFFFFFFFF

#endif