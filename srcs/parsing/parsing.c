/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 04:54:42 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/25 16:23:08 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	fill_player_data(double *player, int row, int col, unsigned int c);
static void	set_player(t_tab *map, double *player);

t_bool	parsing(t_game *game, char *file)
{
	t_parser	parser;
	t_bool		has_error;

	if (validate_filename(file) || init_parser(&parser, file))
		return (FAILURE);
	while (parser.line && !parser.has_error)
	{
		if (ft_str_allinset(parser.line, VALID_MAP_CHARS)
			&& ft_strcmp(parser.line, "\n"))
			parser.in_map = TRUE;
		if (parser.in_map)
			parser.has_error = parse_map(game, &parser);
		else
			parser.has_error = parse_line(game, &parser);
		free(parser.line);
		parser.line = get_next_line(parser.fd);
	}
	has_error = (parser.has_error || validate_map(game->map));
	destroy_parser(&parser);
	if (!has_error)
		set_player(&game->map, game->player);
	return (has_error);
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
