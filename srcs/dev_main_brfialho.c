/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_main_brfialho.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:31:11 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/24 00:33:21 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	if (argc != 2)
// 		return (ft_printf("Wrong number of arguments\n"));
// 	ft_bzero(&game, sizeof(t_game));
// 	t_bool status = parsing(&game, argv[1]);
// 	status ? ft_printf("ERROU\n") : ft_printf("PASSOU\n");
// 	int i = -1;
// 	while (++i < 4)
// 		if (game.path[i])
// 			ft_printf("PATH[%d]: %s\n", i, game.path[i]);
// 	ft_printf("HEX: %X\n", game.mlx.colors[CEILING]);
// 	ft_printf("HEX: %X\n", game.mlx.colors[FLOOR]);
// 	if (game.map.tab)
// 	{
// 		ft_printf("\nROWS: %d COLS: %d\n", game.map.rows, game.map.cols);
// 		ft_split_print((char **)game.map.tab);
// 	}
// 	destroy_game(&game);
// }

void	ft_usleep(long usec)
{
	struct timeval	start;
	struct timeval	now;
	long			time_passed;

	time_passed = 0;
	gettimeofday(&start, NULL);
	while (time_passed < usec)
	{
		gettimeofday(&now, NULL);
		time_passed = (now.tv_sec - start.tv_sec) * 1000000 \
						+ now.tv_usec - start.tv_usec;
	}
}

int	key_release(int keycode, t_game *game)
{
	game->key_is_pressed[(t_uchar)keycode] = FALSE;
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	game->key_is_pressed[(t_uchar)keycode] = TRUE;
	return (0);
}

int	game_loop(t_game *game)
{
	if (game->key_is_pressed[ESC])
		destroy_game(game);
	//LOGIC PART
	for (int i = 0; i < ASCII; i++)
		if (game->key_is_pressed[i])
			ft_printf("%c\n", i);

	// RENDER PART
	draw_floor_and_sky(&game->mlx);
	raycast(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.img, 0, 0);

	return (SUCCESS);
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
	mlx_hook(game.mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &game);
	mlx_hook(game.mlx.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, &game);
	mlx_hook(game.mlx.win, WINDOW_CLOSE, WINDOW_CLOSE_MASK, destroy_game, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
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
