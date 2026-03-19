/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:43:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/19 20:09:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "libft.h"

typedef struct s_texture
{
	char	*path[4];
	int 	colours[2];
} t_texture;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img[4];
	int		width;
	int		height;
} t_mlx;

typedef struct s_game
{
	t_tab		map;
	t_mlx		mlx;
	t_texture	texture;
} t_game;


#endif