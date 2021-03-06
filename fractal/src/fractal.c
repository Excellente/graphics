/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:42:33 by emsimang          #+#    #+#             */
/*   Updated: 2016/10/08 17:04:08 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	is_valid(char *fract)
{
	int	res;

	res = 0;
	if (strcmp(fract, "julia") == 0)
		res = 1;
	else if (strcmp(fract, "mendelbrot") == 0)
		res = 1;
	else if (strcmp(fract, "sierpinski") == 0)
		res = 1;
	return (res);
}

void	draw_fractal(void *m_ptr, void *w_ptr, float zoom, char *fract, float x, float y)
{
	if (strcmp(fract, "julia") == 0)
		draw_julia(m_ptr, w_ptr, zoom);
	else if (strcmp(fract, "mendelbrot") == 0)
		draw_mendelbrot(m_ptr, w_ptr, zoom, x, y);
	else if (strcmp(fract, "sierpinski") == 0)
		draw_sierpinski(m_ptr, w_ptr, zoom);
	else
		return;
}

int main(int ac, char **av)
{
	t_draw	draw;

	if (ac == 2 && is_valid(av[1]))
	{
		draw.zoom = 1.0f;
		draw.fractal = av[1];
		draw.m_ptr = mlx_init();
		draw.w_ptr = mlx_new_window(draw.m_ptr, WIDTH, HEIGHT, draw.fractal);
		draw_fractal(draw.m_ptr, draw.w_ptr, draw.zoom, draw.fractal, -0.5, 0);
		mlx_key_hook(draw.w_ptr, &key_press, &draw);
		mlx_mouse_hook(draw.w_ptr, &mouse_event, &draw);
		mlx_loop(draw.m_ptr);
	}
	else
		printf("error: allowed parameters: julia | mendelbrot | sierpinski\n");
	return (0);
}
