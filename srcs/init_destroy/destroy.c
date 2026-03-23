/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:56 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/23 19:05:31 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	destroy_mlx(t_mlx *mlx);

int	destroy_game(t_game *game)
{
	int	i;

	i = -1;
	while (++i < TEXTURE_COUNT)
		if (game->path[i])
			free(game->path[i]);
	if (game->map.tab)
		ft_tab_free_content(&game->map);
	destroy_mlx(&game->mlx);
	exit(0);
}

void	destroy_parser(t_parser *parser)
{
	gnl_destroy(parser->fd);
	close(parser->fd);
	if (parser->line)
		free(parser->line);
}

static void	destroy_mlx(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < TEXTURE_COUNT)
		if (mlx->textures[i])
			mlx_destroy_image(mlx->mlx_ptr, mlx->textures[i]);
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
