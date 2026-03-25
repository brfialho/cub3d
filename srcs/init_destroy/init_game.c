/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:53:17 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/25 16:41:46 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_bool	init_mlx_display(t_mlx	*mlx, char **path);
static void		set_player(t_tab *map, double *player);
static void		fill_player_data(double *player, int row, int col, unsigned int c);

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
	mlx->textures[NORTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[NORTH], &mlx->width, &mlx->height);
	mlx->textures[SOUTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[SOUTH], &mlx->width, &mlx->height);
	mlx->textures[EAST] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[EAST], &mlx->width, &mlx->height);
	mlx->textures[WEST] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[WEST], &mlx->width, &mlx->height);
	i = -1;
	while (++i < TEXTURE_COUNT)
		if (!mlx->textures[i])
			return (FAILURE);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->win || !mlx->img)
		return (FAILURE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		return (FAILURE);
	return (SUCCESS);
}

static void	set_player(t_tab *map, double *player)
{
	int	row;
	int col;

	row = -1;
	while (++row < (int)map->rows)
	{
		col = -1;
		while (++col < (int)map->cols)
		{
			if (ft_str_charcount(PLAYER_CHARS, ((char **)map->tab)[row][col]))
			{
				fill_player_data(player, row, col, ((char **)map->tab)[row][col]);
				break;
			}
		}
	}	
}

static void	fill_player_data(double *player, int row, int col, unsigned int c)
{
	static const double	spawn[ASCII][4] = {
	['N'] = {0.0, -1.0, MAX_FOV, 0.0},
	['S'] = {0.0, 1.0, MAX_FOV, 0.0},
	['E'] = {1.0, 0.0, 0.0, MAX_FOV},
	['W'] = {-1.0, 0.0, 0.0, MAX_FOV}
	};

	player[POS_X] = col;
	player[POS_Y] = row;
	player[DIR_X] = spawn[c][0];
	player[DIR_Y] = spawn[c][1];
	player[FOV_X] = spawn[c][2];
	player[FOV_Y] = spawn[c][3];
}
