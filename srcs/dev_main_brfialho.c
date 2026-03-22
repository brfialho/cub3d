/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_main_brfialho.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:31:11 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/21 21:59:46 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_bool	validate_filename(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp((file + len - 4), ".cub"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
		return (destroy_parser(parser), EXIT_FAILURE);
	parser->line = get_next_line(parser->fd);
	if (!parser->line)
		return (destroy_parser(parser), EXIT_FAILURE);
	parser->texture[NORTH] = (t_texture){"NO", FALSE};
	parser->texture[SOUTH] = (t_texture){"SO", FALSE};
	parser->texture[EAST] = (t_texture){"EA", FALSE};
	parser->texture[WEST] = (t_texture){"WE", FALSE};
	return (EXIT_SUCCESS);
}

void	parse_line(t_game *game, t_parser *parser)
{
	(void)game;
	(void)parser;
	static int i = 0;
	if (i++ == 2)
		parser->has_error = TRUE;
	
}

t_bool	parsing(t_game *game, char *file)
{
	t_parser	parser;
	t_bool		has_error;

	if (validate_filename(file) || init_parser(&parser, file))
		return (EXIT_FAILURE);
	while (parser.line && !parser.has_error)
	{
		parse_line(game, &parser);
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
	if (parsing(&game, argv[1]))
		ft_printf("ERROU\n"), exit(1);
	ft_printf("PASSOU\n");
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
