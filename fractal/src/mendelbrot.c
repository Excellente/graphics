/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:23:48 by emsimang          #+#    #+#             */
/*   Updated: 2016/10/08 15:49:03 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_mendelbrot(void *m, void *w, float zoom, float x_dir, float y_dir)
{
	t_mendel	mend;

	mend.y = 0;
	while (mend.y < HEIGHT)
	{
		mend.x = 0;
		while (mend.x < WIDTH)
		{
			mend.pixel_real = 1.5 * (mend.x - WIDTH / 2) /
								(0.5 * zoom * WIDTH) -0.5;
			mend.pixel_im = (mend.y - HEIGHT / 2) /
								(0.5 * zoom * HEIGHT);
			mend.i = 0;
			mend.new_real = 0;
			mend.new_imagi = 0;
			mend.old_real = 0;
			mend.old_im = 0;
			while ((mend.new_real * mend.new_real + mend.new_imagi *
								mend.new_imagi) < 4 && mend.i < max)
			{
				mend.old_real = mend.new_real;
				mend.old_im = mend.new_imagi;
				mend.new_real = mend.old_real * mend.old_real - mend.old_im *
								mend.old_im + mend.pixel_real;
				mend.new_imagi = 2 * mend.old_real * mend.old_im + mend.pixel_im;
				mend.i++;
			}
			if (mend.i < max)
				mlx_pixel_put(m, w, mend.x, mend.y, color_palette(mend.i));
			else
				mlx_pixel_put(m, w, mend.x, mend.y, 0x000);
			mend.x++;
		}
		mend.y++;
	}
}
