/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:00:15 by emsimang          #+#    #+#             */
/*   Updated: 2016/10/08 15:21:07 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_julia(void *m_ptr, void *w_ptr, float zoom)
{
	t_julia	jul;

	jul.pix_y = 0;
	jul.real_c = -0.6;
	jul.imagi_c = 0.427015;
	jul.max_iter = 500;
	while (jul.pix_y < HEIGHT)
	{
		jul.pix_x = 0;
		while (jul.pix_x < WIDTH)
		{
			jul.new_real = 1.5 * (jul.pix_x - WIDTH / 2) /
							(0.5 * zoom * WIDTH) + 0;
			jul.new_imagi = (jul.pix_y - HEIGHT / 2) /
							(0.5 * zoom * HEIGHT) + 0;
			jul.iter = 0;
			while ((jul.new_real * jul.new_real + jul.new_imagi
						* jul.new_imagi) < 4 && jul.iter < jul.max_iter)
			{
				jul.old_real = jul.new_real;
				jul.old_imagi = jul.new_imagi;
				jul.new_real = jul.old_real * jul.old_real -
								jul.old_imagi * jul.old_imagi + jul.real_c;
				jul.new_imagi = 2 * jul.old_real * jul.old_imagi +
								jul.imagi_c;
				jul.iter++;
			}
			if (jul.iter < jul.max_iter)
			{
				mlx_pixel_put(m_ptr, w_ptr,jul.pix_x, jul.pix_y
								, color_palette(jul.iter));
			}
			else
				mlx_pixel_put(m_ptr, w_ptr, jul.pix_x, jul.pix_y, 0x000);
			jul.pix_x++;
		}
		jul.pix_y++;
	}
}
