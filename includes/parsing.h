/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 04:52:38 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 16:22:02 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "defines.h"
# include "structs.h"
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_parser
{
	t_bool		status;
	t_bool		in_map;
	int			fd;
	char		*line;
	char		*elements[TYPE_COUNT];
} t_parser;

t_bool	parsing(t_game *game, char *file);
t_bool	parse_map(t_game *game, t_parser *parser);
t_bool	parse_line(t_game *game, t_parser *parser);
t_bool	validate_filename(char *file);
t_bool	validate_map(t_tab map);

#endif