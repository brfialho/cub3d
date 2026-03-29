/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:43:08 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/29 17:31:52 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img;
	t_uint 	colors[COLOR_COUNT];
	int		width;
	int		height;
	
	//image data
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	
	// texture data
	void	*textures[TEXTURE_COUNT];
	char    *tex_addr[TEXTURE_COUNT];
	int     tex_bpp[TEXTURE_COUNT];
	int     tex_line[TEXTURE_COUNT];
	int     tex_width[TEXTURE_COUNT];
	int     tex_height[TEXTURE_COUNT];
	int     tex_endian[TEXTURE_COUNT];
} t_mlx;

typedef struct s_game
{
	t_tab		map;
	t_mlx		mlx;
	t_bool		key_is_pressed[ASCII];
	char		*path[TEXTURE_COUNT];
	double		player[PLAYER_INFO_COUNT];
} t_game;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

typedef struct s_wall
{
    int	height;
    int	start;
    int	end;
    int	tex_x;
}   t_wall;

typedef struct s_wall_data
{
    double  distance;
    double  wall_x;
    int     texture;
}   t_wall_data;

typedef struct s_parser
{
	t_bool		has_error;
	t_bool		in_map;
	int			fd;
	char		*line;
	char		*elements[TYPE_COUNT];
} t_parser;

#endif
