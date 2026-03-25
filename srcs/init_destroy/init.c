/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:53:17 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/24 18:11:52 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx.colors[CEILING] = NO_COLOR;
	game->mlx.colors[FLOOR] = NO_COLOR;
}

t_bool	init_mlx_display(t_mlx	*mlx, char **path)
{
	int	i;

	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (FAILURE);
	mlx->textures[NORTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[NORTH], &mlx->tex_width[NORTH], &mlx->tex_height[NORTH]);
	mlx->textures[SOUTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, path[SOUTH], &mlx->tex_width[SOUTH], &mlx->tex_height[SOUTH]);
	mlx->textures[EAST]  = mlx_xpm_file_to_image(mlx->mlx_ptr, path[EAST],  &mlx->tex_width[EAST],  &mlx->tex_height[EAST]);
	mlx->textures[WEST]  = mlx_xpm_file_to_image(mlx->mlx_ptr, path[WEST],  &mlx->tex_width[WEST],  &mlx->tex_height[WEST]);
	i = -1;
	while (++i < TEXTURE_COUNT)
	{
		if (!mlx->textures[i])
			return (FAILURE);
		mlx->tex_addr[i] = mlx_get_data_addr(mlx->textures[i], &mlx->tex_bpp[i], &mlx->tex_line[i], &mlx->tex_endian[i]);
		if (!mlx->tex_addr[i])
			return (FAILURE);
	}
		
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->win || !mlx->img)
		return (FAILURE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		return (FAILURE);
	return (SUCCESS);
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
