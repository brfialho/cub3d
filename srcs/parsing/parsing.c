/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 04:54:42 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/25 16:38:12 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_bool	init_parser(t_parser *parser, char *file);
static void		destroy_parser(t_parser *parser);

t_bool	parsing(t_game *game, char *file)
{
	t_parser	parser;
	t_bool		has_error;

	ft_bzero(game, sizeof(t_game));
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
	has_error = (parser.has_error || validate_map(game->map));
	destroy_parser(&parser);
	return (has_error);
}

static t_bool	init_parser(t_parser *parser, char *file)
{
	ft_bzero(parser, sizeof(t_parser));
	parser->fd = open(file, O_RDONLY);
	if (parser->fd == -1)
		return (destroy_parser(parser), FAILURE);
	parser->line = get_next_line(parser->fd);
	if (!parser->line)
		return (destroy_parser(parser), FAILURE);
	parser->elements[NORTH] = "NO";
	parser->elements[SOUTH] = "SO";
	parser->elements[EAST] = "EA";
	parser->elements[WEST] = "WE";
	parser->elements[CEILING + 4] = "C";
	parser->elements[FLOOR + 4] = "F";
	return (SUCCESS);
}

static void	destroy_parser(t_parser *parser)
{
	gnl_destroy(parser->fd);
	close(parser->fd);
	if (parser->line)
		free(parser->line);
}
