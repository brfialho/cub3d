/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_main_brfialho.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:31:11 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/21 00:04:08 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include "main.h"

void	parsing(t_tab *map, char **path, int *colors, char *file)
{
	(void)map;
	(void)path;
	(void)colors;
	int	fd;
	char *s;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	while ((s = get_next_line(fd)))
		ft_printf("%d : %s", ft_strlen(s), s);
	
	close(fd);
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
	parsing(&game.map, game.path, game.mlx.colors, argv[1]);
}
