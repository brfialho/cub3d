/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 04:54:42 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 07:06:29 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_bool	validate_filename(char *file);
static t_bool	validate_map_borders(t_tab map);
static t_bool	check_for_open_border(char **map, int row, int col);

t_bool	parsing(t_game *game, char *file)
{
	t_parser	parser;
	t_bool		has_error;

	game->mlx.colors[CEILING] = NO_COLOR;
	game->mlx.colors[FLOOR] = NO_COLOR;
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
	has_error = parser.has_error;
	destroy_parser(&parser);
	return (has_error || validate_map_borders(game->map));
}

static t_bool	validate_filename(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp((file + len - 4), ".cub"))
		return (FAILURE);
	return (SUCCESS);
}

static t_bool	validate_map_borders(t_tab map)
{
	int	row;
	int	col;

	row = -1;
	while (++row < (int)map.rows)
	{
		col = -1;
		while (++col < (int)map.cols)
		{
			if (!row || !col || row == (int)map.rows - 1 || col == (int)map.cols - 1)
			{
				if (!ft_str_charcount("1 ", ((char **)map.tab)[row][col]))
					return (FAILURE);
			}
			else if (((char **)map.tab)[row][col] == ' '
				&& check_for_open_border((char **)map.tab, row, col))
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

static t_bool	check_for_open_border(char **map, int row, int col)
{
	return (!ft_str_charcount(" 1", map[row - 1][col -1])
		|| !ft_str_charcount(" 1", map[row - 1][col])
		|| !ft_str_charcount(" 1", map[row - 1][col + 1])
		|| !ft_str_charcount(" 1", map[row][col - 1])
		|| !ft_str_charcount(" 1", map[row][col + 1])
		|| !ft_str_charcount(" 1", map[row + 1][col - 1])
		|| !ft_str_charcount(" 1", map[row + 1][col])
		|| !ft_str_charcount(" 1", map[row + 1][col + 1]));
}
