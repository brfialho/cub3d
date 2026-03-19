/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/19 20:13:19 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_bool	init_mlx_display(t_game	*game)
{
	(void)game;
	game->mlx.mlx_ptr = mlx_init();
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, 400, 400, "Cub3d");
	game->mlx.img[north] = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "sprites/teste.xpm", &game->mlx.width, &game->mlx.height);

	return (EXIT_SUCCESS);
}

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	if (init_mlx_display(game))
		exit(1);
}

int	game_loop(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img[north], 0, 200);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_game	game;

	init_game(&game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
