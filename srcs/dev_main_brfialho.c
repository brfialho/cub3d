/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_main_brfialho.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:31:11 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 07:14:11 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
			ft_printf("PATH[%d]: %s\n", i, game.path[i]);
	ft_printf("HEX: %X\n", game.mlx.colors[CEILING]);
	ft_printf("HEX: %X\n", game.mlx.colors[FLOOR]);
	if (game.map.tab)
	{
		ft_printf("\nROWS: %d COLS: %d\n", game.map.rows, game.map.cols);
		ft_split_print((char **)game.map.tab);
	}
	destroy_game(&game);
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
