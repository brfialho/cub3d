/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/19 19:27:47 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_bool	init_mlx(t_game	*game)
{
	game->mlx;
}

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	if (init_mlx(game))
		exit(1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_game	game;

	init_game(&game);

	ft_printf("Cub3d\n");
}
