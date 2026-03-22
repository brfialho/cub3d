/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_main_brfialho.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:31:11 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 04:29:33 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_bool	validate_filename(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp((file + len - 4), ".cub"))
		return (FAILURE);
	return (SUCCESS);
}

void	destroy_parser(t_parser *parser)
{
	gnl_destroy(parser->fd);
	close(parser->fd);
	if (parser->line)
		free(parser->line);
}

t_bool	init_parser(t_parser *parser, char *file)
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

t_bool	check_for_missing_elements(t_game *game)
{
	int	i;

	i = -1;
	while (++i < TEXTURE_COUNT)
		if (!game->path[i])
			return (FAILURE);
	i = -1;
	while (++i < COLOR_COUNT)
		if (game->mlx.colors[i] == NO_COLOR)
			return (FAILURE);
	return (SUCCESS);
}

void	set_map(t_tab *map, char *dump_map, size_t max_len)
{
	char	**split;
	int		i;
	size_t	split_len;

	split = ft_split(dump_map, '\n');
	split_len = ft_split_len(split);
	ft_tab_init_alloc(map, split_len + 1, max_len + 1, sizeof(char));
	i = -1;
	while (split[++i])
		ft_memcpy(map->tab[i], split[i], ft_strlen(split[i]));
	ft_split_free(split);
}

t_bool	parse_map(t_game *game, t_parser *parser)
{
	char	*dump_map;
	char	*buffer;
	size_t	max_len;
	size_t	buffer_len;

	if (check_for_missing_elements(game))
		return (FAILURE);
	(void)parser;
	dump_map = ft_strdup("");
	buffer = ft_strdup(parser->line);
	max_len = 0;
	while (buffer)
	{
		buffer_len = ft_strlen(buffer);
		if (max_len < buffer_len)
			max_len = ft_strlen(buffer);
		if (!ft_strcmp(buffer, "\n")
			|| !ft_str_allinset(buffer, VALID_MAP_CHARS))
			return (free(buffer), free(dump_map), FAILURE);
		dump_map = ft_strjoin_free(dump_map, buffer, TRUE, TRUE);
		buffer = get_next_line(parser->fd);
	}
	set_map(&game->map, dump_map, max_len);
	free(dump_map);
	return (SUCCESS);
}

t_bool	set_color(t_uint *color, char *color_str)
{
	t_uint	rgb[3];
	char	**split;
	int		i;

	split = ft_split(color_str, ',');
	if (ft_split_len(split) != 3 || ft_strlen(split[2]) == 1)
		return (ft_split_free(split), FAILURE);
	i = -1;
	while (++i < 3)
	{
		if (!ft_str_allinset(split[i], "0123456789\n"))
			return (ft_split_free(split), FAILURE);
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] > 0xFF || rgb[i] < 0)
			return (ft_split_free(split), FAILURE);
	}
	*color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	ft_split_free(split);
	return (SUCCESS);
}

t_bool	parse_line(t_game *game, t_parser *parser)
{
	t_bool	status;
	char	**split;
	int		element;

	if (!ft_strcmp(parser->line, "\n"))
		return (SUCCESS);
	split = ft_split(parser->line, ' ');
	if (ft_split_len(split) != 2)
		return (ft_split_free(split), FAILURE);
	element = -1;
	while (ft_strcmp(split[0], parser->elements[++element]))
		if (element > TYPE_COUNT - 1)
			return (ft_split_free(split), FAILURE);
	status = SUCCESS;
	if (element < TEXTURE_COUNT && !game->path[element])
		game->path[element] = ft_strdup(split[1]);
	else if (game->mlx.colors[element - TEXTURE_COUNT] == NO_COLOR)
		status = set_color(&game->mlx.colors[element - TEXTURE_COUNT], split[1]);
	else
		status = FAILURE;
	ft_split_free(split);
	return (status);
}

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
	return (has_error);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Wrong number of arguments\n"));
	ft_bzero(&game, sizeof(t_game));
	t_bool status = parsing(&game, argv[1]);
	(status && ft_printf("ERROU\n")) || ft_printf("PASSOU\n");
	int i = -1;
	while (++i < 4)
		if (game.path[i])
		{
			ft_printf("PATH[%d]: %s\n", i, game.path[i]);
			free(game.path[i]);
		}
	ft_printf("HEX: %X\n", game.mlx.colors[CEILING]);
	ft_printf("HEX: %X\n", game.mlx.colors[FLOOR]);
	if (game.map.tab)
	{
		ft_printf("\nROWS: %d COLS: %d\n", game.map.rows, game.map.cols);
		ft_split_print((char **)game.map.tab);
		ft_tab_free_content(&game.map);
	}
}
// int main()
// {
// 	int fd = open("maps/valid/1.cub", O_RDONLY);
// 	free(get_next_line(fd));

// 	// destroy gnl
// 	char *s;
// 	while ((s = get_next_line(fd)))
// 		free(s);
// 	close(fd);
// }
