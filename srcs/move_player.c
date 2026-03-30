/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:36:17 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/29 21:30:48 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		rotate_player(t_game *game, double angle);
static double	move_x(char *key, double dir_x, double dir_y);
static double	move_y(char *key, double dir_x, double dir_y);
static void		update_player_pos(t_game *game, double new_x, double new_y);

void	move_player(t_game *game)
{
	double	angle;

	angle = (game->key_is_pressed[LEFT_ARROW] * -TURN_SPEED)
		+ game->key_is_pressed[RIGHT_ARROW] * TURN_SPEED;
	rotate_player(game, angle);
	update_player_pos(game, game->player[POS_X]
		+ move_x(game->key_is_pressed,
			game->player[DIR_X], game->player[DIR_Y]), game->player[POS_Y]
		+ move_y(game->key_is_pressed,
			game->player[DIR_X], game->player[DIR_Y]));
}

static void	rotate_player(t_game *game, double angle)
{
	double	dir_x;
	double	dir_y;
	double	fov_x;
	double	fov_y;

	dir_x = game->player[DIR_X];
	dir_y = game->player[DIR_Y];
	fov_x = game->player[FOV_X];
	fov_y = game->player[FOV_Y];
	game->player[DIR_X] = !!angle * (dir_x * cos(angle) - dir_y * sin(angle))
		+ !angle * (dir_x);
	game->player[DIR_Y] = !!angle * (dir_x * sin(angle) + dir_y * cos(angle))
		+ !angle * (dir_y);
	game->player[FOV_X] = fov_x * cos(angle) - fov_y * sin(angle);
	game->player[FOV_Y] = fov_x * sin(angle) + fov_y * cos(angle);
}

static double	move_x(char *key, double dir_x, double dir_y)
{
	return ((key['w'] * (MOVE_SPEED * dir_x))
		+ (key['s'] * (-MOVE_SPEED * dir_x))
		+ ((key['d']) * (
				((dir_x > 0) * (dir_y < 0)
					* MOVE_SPEED * fabs(dir_y))
				+ ((dir_x > 0) * (dir_y > 0)
					* MOVE_SPEED * -dir_y)
				+ ((dir_x < 0) * (dir_y > 0)
					* MOVE_SPEED * -dir_y)
				+ ((dir_x < 0) * (dir_y < 0)
					* MOVE_SPEED * -dir_y)
				+ ((dir_y < 0) * MOVE_SPEED * -dir_y)
				+ ((dir_y > 0) * MOVE_SPEED * -dir_y)
			))
		+ ((key['a']) * (
				((dir_x > 0) * (dir_y < 0)
					* MOVE_SPEED * dir_y)
				+ ((dir_x > 0) * (dir_y > 0)
					* MOVE_SPEED * dir_y)
				+ ((dir_x < 0) * (dir_y > 0)
					* MOVE_SPEED * dir_y)
				+ ((dir_x < 0) * (dir_y < 0)
					* MOVE_SPEED * dir_y)
				+ ((dir_y < 0) * MOVE_SPEED * dir_y)
				+ ((dir_y > 0) * MOVE_SPEED * dir_y))));
}

static double	move_y(char *key, double dir_x, double dir_y)
{
	return ((key['w'] * (MOVE_SPEED * dir_y))
		+ (key['s'] * (-MOVE_SPEED * dir_y))
		+ ((key['d']) * (
				((dir_x > 0) * (dir_y < 0)
					* MOVE_SPEED * fabs(dir_x))
				+ ((dir_x > 0) * (dir_y > 0)
					* MOVE_SPEED * dir_x)
				+ ((dir_x < 0) * (dir_y > 0)
					* MOVE_SPEED * dir_x)
				+ ((dir_x < 0) * (dir_y < 0)
					* MOVE_SPEED * dir_x)
				+ ((dir_x < 0) * MOVE_SPEED * dir_x)
				+ ((dir_x > 0) * MOVE_SPEED * dir_x)
			))
		+ ((key['a']) * (
				((dir_x > 0) * (dir_y < 0)
					* MOVE_SPEED * -dir_x)
				+ ((dir_x > 0) * (dir_y > 0)
					* MOVE_SPEED * -dir_x)
				+ ((dir_x < 0) * (dir_y > 0)
					* MOVE_SPEED * -dir_x)
				+ ((dir_x < 0) * (dir_y < 0)
					* MOVE_SPEED * -dir_x)
				+ ((dir_x < 0) * MOVE_SPEED * -dir_x)
				+ ((dir_x > 0) * MOVE_SPEED * -dir_x))));
}

static void	update_player_pos(t_game *game, double new_x, double new_y)
{
	t_bool		found_wall;
	double		diff;
	char		**map;
	

	diff = new_x - game->player[POS_X];
	map = (char **)game->map.tab;
	found_wall = (map[(int)game->player[POS_Y]][(int)(new_x + (diff * 4))] == '1');
	game->player[POS_X] = found_wall * game->player[POS_X]
		+ !found_wall * new_x;
	diff = new_y - game->player[POS_Y];
	found_wall = (map[(int)(new_y + (diff * 4))][(int)game->player[POS_X]] == '1');
	game->player[POS_Y] = found_wall * game->player[POS_Y]
		+ !found_wall * new_y;
}

// x = 0.8 | 0.9 | 0.9
// y =1.5 | 1.6 | 1.7

// 0.8 -> 0.9 = 0.1
// 0.9 -> 0.8 = -0.1