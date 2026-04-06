/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 04:54:42 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 20:53:04 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_bool	init_parser(t_parser *parser, char *file, t_game *game);
static void		destroy_parser(t_parser *parser);
static void		print_error(t_uint	error_code);

t_bool	parsing(t_game *game, char *file)
{
	t_parser	parser;
	t_uint		status;

	if (validate_filename(file) || init_parser(&parser, file, game))
		return (FAILURE);
	while (parser.line && !parser.status)
	{
		if (ft_str_allinset(parser.line, VALID_MAP_CHARS)
			&& ft_strcmp(parser.line, "\n"))
			parser.in_map = TRUE;
		if (parser.in_map)
			parser.status = parse_map(game, &parser);
		else
			parser.status = parse_line(game, &parser);
		free(parser.line);
		parser.line = get_next_line(parser.fd);
	}
	if (parser.status)
		status = parser.status;
	else
		status = validate_map(game->map);
	destroy_parser(&parser);
	if (status)
		print_error(status);
	return (status);
}

static t_bool	init_parser(t_parser *parser, char *file, t_game *game)
{
	ft_bzero(parser, sizeof(t_parser));
	game->mlx.colors[CEILING] = NO_COLOR;
	game->mlx.colors[FLOOR] = NO_COLOR;
	parser->fd = open(file, O_RDONLY);
	if (parser->fd == -1)
	{
		ft_printf(TITLE ": error: could not open file '%s'\n", file);
		return (destroy_parser(parser), FAILURE);
	}
	parser->line = get_next_line(parser->fd);
	if (!parser->line)
	{
		ft_printf(TITLE ": error: empty file\n");
		return (destroy_parser(parser), FAILURE);
	}
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

static void	print_error(t_uint	error_code)
{
	static char	*error_message[256] = {0};
	int			i;

	error_message[ERROR_PARSER] = "parser error";
	error_message[ERROR_MAP] = "invalid map";
	error_message[ERROR_MULTI_ELEMT] = "wrong number of map elements";
	error_message[ERROR_INLINE_MULTI_ELEMT] = "multiple items in line";
	error_message[ERROR_IDENTIFIER] = "invalid identifier";
	error_message[ERROR_C_MULTI] = "invalid rgb";
	error_message[ERROR_C_NUM] = "non numeric rgb";
	error_message[ERROR_C_VALUE] = "rgb value not between 0-255";
	error_message[ERROR_OPEN_BORDER] = "map has open borders";
	error_message[ERROR_PLAYER_COUNT] = "invalid player count";
	error_message[ERROR_REPEAT_ELEMENT] = "map element repeated";
	i = -1;
	while (++i < 13)
		if (i == (int)error_code)
			ft_printf(TITLE ": error: %s\n", error_message[i]);
}
