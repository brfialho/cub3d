/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/25 23:27:23 by brfialho         ###   ########.fr       */
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
	mlx_hook(game.mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &game);
	mlx_hook(game.mlx.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, &game);
	mlx_hook(game.mlx.win, WINDOW_CLOSE, WINDOW_CLOSE_MASK, destroy_game, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
}

void	move_player(t_game *game)
{	
	// double	DirX;
	// double	DirY;

	game->player[DIR_X] = 0;
	game->player[DIR_Y] = -0.1;

	// game->player[DIR_X] += game->key_is_pressed[65361] * (TURN_SPEED * ((DirY < 0) - (DirY >= 0)));
	// game->player[DIR_Y] += game->key_is_pressed[65363] * (TURN_SPEED * ((DirX >= 0) - (DirX < 0)));
	// game->player[DIR_X] -= game->key_is_pressed['a'] * (TURN_SPEED * ((game->player[DIR_Y] > 0)));
	// game->player[DIR_Y] -= game->key_is_pressed['a'] * (TURN_SPEED * ((game->player[DIR_X] > 0)));

	game->player[POS_X] += ((game->key_is_pressed['w'] * (MOVE_SPEED * game->player[DIR_X]))
							+ (game->key_is_pressed['s'] * -1 * (MOVE_SPEED * game->player[DIR_X]))
							+ ((game->key_is_pressed['d']) * (
								((game->player[DIR_X] > 0) * (game->player[DIR_Y] < 0) * MOVE_SPEED * fabs(game->player[DIR_Y]))
								+ ((game->player[DIR_X] > 0) * (game->player[DIR_Y] > 0) * MOVE_SPEED * game->player[DIR_Y] * -1)
								+ ((game->player[DIR_X] < 0) * (game->player[DIR_Y] > 0) * MOVE_SPEED * game->player[DIR_Y] * -1)
								+ ((game->player[DIR_X] < 0) * (game->player[DIR_Y] < 0) * MOVE_SPEED * game->player[DIR_Y] * -1)
							))
							);
	game->player[POS_Y] += ((game->key_is_pressed['w'] * (MOVE_SPEED * game->player[DIR_Y]))
							+ (game->key_is_pressed['s'] * -1 * (MOVE_SPEED * game->player[DIR_Y]))
							+ ((game->key_is_pressed['d']) * (
								((game->player[DIR_X] > 0) * (game->player[DIR_Y] < 0) * MOVE_SPEED * fabs(game->player[DIR_X]))
								+ ((game->player[DIR_X] > 0) * (game->player[DIR_Y] > 0) * MOVE_SPEED * game->player[DIR_X])
								+ ((game->player[DIR_X] < 0) * (game->player[DIR_Y] > 0) * MOVE_SPEED * game->player[DIR_X])
								+ ((game->player[DIR_X] < 0) * (game->player[DIR_Y] < 0) * MOVE_SPEED * game->player[DIR_X])
							))
							);
}

static int	game_loop(t_game *game)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	if (game->key_is_pressed[ESC])
		destroy_game(game);

	// LOGIC PART
	// for (int i = 0; i < ASCII; i++)
	// 	if (game->key_is_pressed[i])
	// 		ft_printf("%d\n", i);
	move_player(game);

	#include <stdio.h>
	printf("\033[3J\033[H\nPLAYER POS -> Y:%f X:%f\nDirX: %f DirY: %f\n", game->player[POS_Y], game->player[POS_X], game->player[DIR_X], game->player[DIR_Y]);

	// RENDER PART
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
	time_passed = (end.tv_sec - start->tv_sec) * 1000000 + end.tv_usec - start->tv_usec;
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

// OLHAR ESQUERDA || X = -1
// OLHAR DIREITA || X = 1

// OLHAR CIMA || Y = -1
// OLHAR PRA BAIXO || Y = 1