/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 14:18:52 by emsimang          #+#    #+#             */
/*   Updated: 2016/10/08 14:30:07 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_event(int keycode, int x, int y, t_draw *draw)
{
	draw->zoom += 0.01f;
	x /= WIDTH;
	y /= HEIGHT;
	if (keycode == MOUSE_ROLL_UP)
		draw_fractal(draw->m_ptr, draw->w_ptr, draw->zoom, draw->fractal, x, y);
	return (1);
}

int	key_press(int keycode, t_draw *draw)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (1);
}
