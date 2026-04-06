/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 13:12:25 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	game_loop(t_game *game);
static void	fix_timerate(struct timeval *start);
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
	move_player(game);

	#include <stdio.h>
	printf("\033[3J\033[H\nPLAYER POS -> Y:%f X:%f\nDirX: %f DirY: %f\n", game->player[POS_Y], game->player[POS_X], game->player[DIR_X], game->player[DIR_Y]);

	draw_floor_and_sky(&game->mlx);
	raycast(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.img, 0, 0);
	fix_timerate(&start);
	return (SUCCESS);
}

static void	fix_timerate(struct timeval *start)
{
	struct timeval	end;
	long			time_passed;

	gettimeofday(&end, NULL);
	time_passed = (end.tv_sec - start->tv_sec) * 1000000
		+ end.tv_usec - start->tv_usec;
	if (time_passed < ONE_SIXTIETH_OF_SEC)
		ft_usleep(ONE_SIXTIETH_OF_SEC - time_passed);
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
