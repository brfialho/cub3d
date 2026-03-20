/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:26:21 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/20 20:41:24 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


void	destroy_mlx(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < TEXTURE_COUNT)
		if (mlx->textures[i])
			free(mlx->textures[i]);
	if (mlx->img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}

void	destroy_game(t_game *game)
{
	destroy_mlx(&game->mlx);
	exit(0);
}

t_bool	init_mlx_display(t_mlx	*mlx, char **path)
{
	//MOCADNDO POR ENQUANTO
	path[NORTH] = "assets/teste.xpm";
	path[SOUTH] = "assets/teste2.xpm";
	path[EAST] = "assets/teste3.xpm";
	path[WEST] = "assets/teste4.xpm";
	int	i;

	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->win || !mlx->img)
		return (EXIT_FAILURE);
	mlx->textures[NORTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[NORTH], &mlx->width, &mlx->height);
	mlx->textures[SOUTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[SOUTH], &mlx->width, &mlx->height);
	mlx->textures[EAST] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[EAST], &mlx->width, &mlx->height);
	mlx->textures[WEST] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[WEST], &mlx->width, &mlx->height);
	i = -1;
	while (++i < TEXTURE_COUNT)
		if (!mlx->textures[i])
		{
			ft_printf("%d\n", i);
			return (EXIT_FAILURE);
		}
	return (EXIT_SUCCESS);
}

int	game_loop(t_game *game)
{
	static int i = 0;

	// usleep(1000);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.textures[i++ % 2], 0, 200);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (init_mlx_display(&game.mlx, game.path))
		destroy_game(&game);
	ft_printf("AAAA");
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
