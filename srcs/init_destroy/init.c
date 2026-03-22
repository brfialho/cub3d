/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:53:17 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 04:53:45 by brfialho         ###   ########.fr       */
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

t_bool	init_parser(t_parser *parser, char *file)
{
	ft_bzero(parser, sizeof(t_parser));
	parser->fd = open(file, O_RDONLY);
	if (parser->fd == -1)
		return (destroy_parser(parser), FAILURE);
	parser->line = get_next_line(parser->fd);
	if (!parser->line)
		return (destroy_parser(parser), FAILURE);
	parser->elements[NORTH] = "NO";
	parser->elements[SOUTH] = "SO";
	parser->elements[EAST] = "EA";
	parser->elements[WEST] = "WE";
	parser->elements[CEILING + 4] = "C";
	parser->elements[FLOOR + 4] = "F";
	return (SUCCESS);
}
