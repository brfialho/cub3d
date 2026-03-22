/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 04:56:04 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 08:21:28 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_bool	set_color(t_uint *color, char *color_str);

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
	{
		game->path[element] = ft_strdup(split[1]);
		game->path[element][ft_strlen(game->path[element]) - 1] = '\0';
	}
	else if (game->mlx.colors[element - TEXTURE_COUNT] == NO_COLOR)
		status = set_color(&game->mlx.colors[element - TEXTURE_COUNT], split[1]);
	else
		status = FAILURE;
	ft_split_free(split);
	return (status);
}

static t_bool	set_color(t_uint *color, char *color_str)
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
