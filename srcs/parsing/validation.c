/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:14:45 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/28 03:02:04 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_bool	check_for_open_border(t_tab map, int row, int col);

t_bool	validate_filename(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp((file + len - 4), ".cub"))
		return (FAILURE);
	return (SUCCESS);
}

t_bool	validate_map(t_tab map)
{
	int	row;
	int	col;
	int	player_count;

	row = -1;
	player_count = 0;
	while (++row < (int)map.rows)
	{
		col = -1;
		while (++col < (int)map.cols)
		{
			player_count += ft_str_charcount(PLAYER_CHARS,
					((char **)map.tab)[row][col]);
			if (check_for_open_border(map, row, col))
				return (FAILURE);
		}
	}
	return ((player_count != 1));
}

static t_bool	check_for_open_border(t_tab map, int row, int col)
{
	if (!row || !col || row == (int)map.rows - 1 || col == (int)map.cols - 1)
	{
		if (!ft_str_charcount("1 ", ((char **)map.tab)[row][col]))
			return (FAILURE);
	}
	else if (((char **)map.tab)[row][col] == ' '
		&& (!ft_str_charcount(" 1", ((char **)map.tab)[row - 1][col -1])
		|| !ft_str_charcount(" 1", ((char **)map.tab)[row - 1][col])
		|| !ft_str_charcount(" 1", ((char **)map.tab)[row - 1][col + 1])
		|| !ft_str_charcount(" 1", ((char **)map.tab)[row][col - 1])
		|| !ft_str_charcount(" 1", ((char **)map.tab)[row][col + 1])
		|| !ft_str_charcount(" 1", ((char **)map.tab)[row + 1][col - 1])
		|| !ft_str_charcount(" 1", ((char **)map.tab)[row + 1][col])
		|| !ft_str_charcount(" 1", ((char **)map.tab)[row + 1][col + 1])))
		return (FAILURE);
	return (SUCCESS);
}
