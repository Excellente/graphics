/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 16:47:14 by emsimang          #+#    #+#             */
/*   Updated: 2016/10/08 16:55:07 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_sierpinski(void *m_ptr, void *w_ptr, float zoom)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!((x / 1) % 3 == 1 && (y / 1) % 3 == 1)
				&&
				!((x / 3) % 3 == 1 && (y / 3) % 3 == 1)
				&&
				!((x / 9) % 3 == 1 && (y / 9) % 3 == 1)
				&&
				!((x / 27) % 3 == 1 && (y / 27) % 3 == 1)
				&&
				!((x / 81) % 3 == 1 && (y / 81) % 3 == 1))
				mlx_pixel_put(m_ptr, w_ptr, x, y, color_palette(x + y));
			x++;
		}
		y++;
	}
}
