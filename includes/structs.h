/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:43:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/21 22:42:18 by gbercaco         ###   ########.fr       */
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
	int 	colours[COLOUR_COUNT];
	int		width;
	int		height;

	//image data
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_mlx;

typedef struct s_game
{
	t_tab		map;
	t_mlx		mlx;
	char	*path[TEXTURE_COUNT];
} t_game;

#endif
