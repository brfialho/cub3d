/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/23 19:13:26 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	game_loop(t_game *game)
{
	draw_floor_and_sky(&game->mlx);
	raycast(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.img, 0, 0);
	
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_game	game;

	if (argc != 2)
		return (ft_printf("Wrong number of arguments\n"));
	ft_bzero(&game, sizeof(t_game));
	if (parsing(&game, argv[1]))
		destroy_game(&game);
	if (init_mlx_display(&game.mlx, game.path))
		destroy_game(&game);
	mlx_hook(game.mlx.win, WINDOW_CLOSE, WINDOW_CLOSE_MASK, destroy_game, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
