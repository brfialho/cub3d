/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_main_brfialho.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:31:11 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/21 00:42:39 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include "main.h"

t_bool	validate_filename(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp((file + len - 4), ".cub"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	parsing(t_game *game, char *file)
{
	(void)game;

	if (validate_filename(file))
		exit(EXIT_FAILURE);
	// int	fd;
	// char *s;

	// fd = open(file, O_RDONLY);
	// if (fd == -1)
	// 	exit(1);
	// while ((s = get_next_line(fd)))
	// 	ft_printf("%d : %s", ft_strlen(s), s);
	
	// close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(&game, sizeof(t_game));
	parsing(&game, argv[1]);
	ft_printf("PASSOU\n");
}
