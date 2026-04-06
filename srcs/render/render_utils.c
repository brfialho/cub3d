/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:04:45 by brfialho          #+#    #+#             */
/*   Updated: 2026/04/06 17:05:56 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img_data.addr + (y * mlx->img_data.line_len + x
			* (mlx->img_data.bpp / 8));
	*(unsigned int *)dst = color;
}

int	return_pixel(t_mlx *mlx, int x, int y, int texuture)
{
	char	*dst;

	dst = mlx->tex_data.addr[texuture] + (y * mlx->tex_data.line[texuture]
			+ x * (mlx->tex_data.bpp[texuture] / 8));
	return (*(unsigned int *)dst);
}
