/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 14:15:16 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	game_loop(t_game *game);
static int	key_release(int keycode, t_game *game);
static int	key_press(int keycode, t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Wrong number of arguments\n"));
	if (parsing(&game, argv[1]) || init_game(&game))
		destroy_game(&game);
	mlx_hook(game.mlx.win, KEY_PRESS, 1L << 0, key_press, &game);
	mlx_hook(game.mlx.win, KEY_RELEASE, 1L << 1, key_release, &game);
	mlx_hook(game.mlx.win, WINDOW_CLOSE, 1l << 17, destroy_game, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
}

static int	game_loop(t_game *game)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	if (game->key_is_pressed[ESC])
		destroy_game(game);
	draw_floor_and_sky(&game->mlx);
	raycast(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.img, 0, 0);
	move_player(game, ft_get_deltat(&start));
	return (SUCCESS);
}

static int	key_release(int keycode, t_game *game)
{
	game->key_is_pressed[(t_uchar)keycode] = FALSE;
	return (0);
}

static int	key_press(int keycode, t_game *game)
{
	game->key_is_pressed[(t_uchar)keycode] = TRUE;
	return (0);
}
