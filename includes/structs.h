/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:43:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/21 19:09:13 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "libft.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img;
	void	*textures[TEXTURE_COUNT];
	int 	colors[COLOUR_COUNT];
	int		width;
	int		height;
} t_mlx;

typedef struct s_game
{
	t_tab		map;
	t_mlx		mlx;
	char	*path[TEXTURE_COUNT];
} t_game;

typedef struct s_texture
{
	char	*str;
	t_bool	found;
} t_texture;

typedef struct s_parser
{
	int			fd;
	char		*line;
	t_texture	texture[TEXTURE_COUNT];
	t_bool		has_error;
} t_parser;

#endif