/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 04:56:04 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 17:29:48 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_bool	set_color(t_uint *color, char *color_str);

t_bool	parse_line(t_game *game, t_parser *parser)
{
	t_bool	status;
	char	**split;
	int		item;

	if (!ft_strcmp(parser->line, "\n"))
		return (SUCCESS);
	split = ft_split(parser->line, ' ');
	if (ft_split_len(split) != 2)
		return (ft_split_free(split), ERROR_INLINE_MULTI_ELEMT);
	item = -1;
	while (ft_strcmp(split[0], parser->elements[++item]))
		if (item == TYPE_COUNT - 1)
			return (ft_split_free(split), ERROR_IDENTIFIER);
	status = SUCCESS;
	if (item < TEXTURE_COUNT && !game->path[item])
	{
		game->path[item] = ft_strdup(split[1]);
		game->path[item][ft_strlen(game->path[item]) - 1] = '\0';
	}
	else if (game->mlx.colors[item - TEXTURE_COUNT] == NO_COLOR)
		status = set_color(&game->mlx.colors[item - TEXTURE_COUNT], split[1]);
	else
		status = ERROR_REPEAT_ELEMENT;
	ft_split_free(split);
	return (status);
}

static t_bool	set_color(t_uint *color, char *color_str)
{
	int		rgb[3];
	char	**split;
	int		i;

	split = ft_split(color_str, ',');
	if (ft_split_len(split) != 3 || ft_strlen(split[2]) == 1)
		return (ft_split_free(split), ERROR_C_MULTI);
	i = -1;
	while (++i < 3)
	{
		if (!ft_str_allinset(split[i], "0123456789\n"))
			return (ft_split_free(split), ERROR_C_NUM);
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] > 0xFF || rgb[i] < 0)
			return (ft_split_free(split), ERROR_C_VALUE);
	}
	*color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	ft_split_free(split);
	return (SUCCESS);
}
