/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:53:17 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/21 15:46:04 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	mlx->textures[NORTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[NORTH], &mlx->width, &mlx->height);
	mlx->textures[SOUTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[SOUTH], &mlx->width, &mlx->height);
	mlx->textures[EAST] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[EAST], &mlx->width, &mlx->height);
	mlx->textures[WEST] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[WEST], &mlx->width, &mlx->height);
	i = -1;
	while (++i < TEXTURE_COUNT)
		if (!mlx->textures[i])
			return (EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->win || !mlx->img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
