/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 04:56:57 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 05:59:07 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_bool	check_for_missing_elements(t_game *game);
static void		set_map(t_tab *map, char *dump_map, size_t max_len);

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

static t_bool	check_for_missing_elements(t_game *game)
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

static void	set_map(t_tab *map, char *dump_map, size_t max_len)
{
	char	**split;
	int		i;
	size_t	split_len;

	split = ft_split(dump_map, '\n');
	split_len = ft_split_len(split);
	ft_tab_init_alloc(map, split_len, max_len - 1, sizeof(char));
	ft_printf ("MAX: %d\n", max_len);
	i = -1;
	while (split[++i])
	{
		ft_memset(map->tab[i], ' ', max_len - 1);
		ft_memcpy(map->tab[i], split[i], ft_strlen(split[i]));
	}
	ft_split_free(split);
}
