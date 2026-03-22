/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:43:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 09:24:49 by brfialho         ###   ########.fr       */
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
	t_uint 	colors[COLOR_COUNT];
	int		width;
	int		height;
} t_mlx;

typedef struct s_game
{
	t_tab		map;
	t_mlx		mlx;
	char	*path[TEXTURE_COUNT];
} t_game;

typedef struct s_parser
{
	t_bool		has_error;
	t_bool		in_map;
	int			fd;
	char		*line;
	char		*elements[TYPE_COUNT];
} t_parser;

#endif