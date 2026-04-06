/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:53:17 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 19:49:49 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_bool	init_mlx_display(t_mlx	*mlx, char **path);
static void		set_player(t_tab *map, double *player);
static void		fill_player_data(double *player, int row, int col,
					unsigned int c);

t_bool	init_game(t_game *game)
{
	set_player(&game->map, game->player);
	if (init_mlx_display(&game->mlx, game->path))
		return (destroy_game(game), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static t_bool	init_mlx_display(t_mlx	*mlx, char **path)
{
	int	i;

	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (FAILURE);
	i = -1;
	while (++i < TEXTURE_COUNT)
	{
		mlx->tex_data.textures[i] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[i],
				&mlx->tex_data.width[i], &mlx->tex_data.height[i]);
		if (!mlx->tex_data.textures[i])
			return (FAILURE);
		mlx->tex_data.addr[i] = mlx_get_data_addr(mlx->tex_data.textures[i],
				&mlx->tex_data.bpp[i],
				&mlx->tex_data.line[i], &mlx->tex_data.endian[i]);
		if (!mlx->tex_data.addr[i])
			return (FAILURE);
	}
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->win || !mlx->img)
		return (FAILURE);
	return (!(mlx->img_data.addr = mlx_get_data_addr(mlx->img,
				&mlx->img_data.bpp,
				&mlx->img_data.line_len, &mlx->img_data.endian)));
}

static void	set_player(t_tab *map, double *player)
{
	int	row;
	int	col;

	row = -1;
	while (++row < (int)map->rows)
	{
		col = -1;
		while (++col < (int)map->cols)
		{
			if (ft_str_charcount(PLAYER_CHARS, ((char **)map->tab)[row][col]))
			{
				fill_player_data(player, row, col,
					((char **)map->tab)[row][col]);
				break ;
			}
		}
	}	
}

static void	fill_player_data(double *player, int row, int col, unsigned int c)
{
	static const double	spawn[ASCII][4] = {
	['N'] = {0.0, -1.0, MAX_FOV, 0.0},
	['S'] = {0.0, 1.0, -MAX_FOV, 0.0},
	['E'] = {1.0, 0.0, 0.0, MAX_FOV},
	['W'] = {-1.0, 0.0, 0.0, -MAX_FOV}
	};

	player[POS_X] = col;
	player[POS_Y] = row;
	player[DIR_X] = spawn[c][0];
	player[DIR_Y] = spawn[c][1];
	player[FOV_X] = spawn[c][2];
	player[FOV_Y] = spawn[c][3];
}
