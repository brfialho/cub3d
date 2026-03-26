/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texte.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:27:28 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/25 21:29:42 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

double get_player_angle(double dirX, double dirY)
{
	double angle = atan2(dirX, dirY) * (180.0 / M_PI);
	if (angle < 0)
		angle += 360.0;
	return angle;
}


int main(){
	// double s = 0.05;
	// double x = 0.3;
	// double y = 0.5;
	// x+= (s * (((((int)(y * 100)) >> 31) & 1)) + (((((int)(y * 100)) >> 31) & 1)));
	// printf("x: %f\n", x);

	double dirX = 0;
	double dirY = 1;
	double angle = get_player_angle(dirX, dirY);
	printf("Player angle: %f\n", angle);
}