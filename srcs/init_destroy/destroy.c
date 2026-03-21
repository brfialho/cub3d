/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:56 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/20 20:57:13 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	destroy_mlx(t_mlx *mlx);

int	destroy_game(t_game *game)
{
	destroy_mlx(&game->mlx);
	exit(0);
	return (0);
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
