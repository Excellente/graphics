/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 11:12:02 by emsimang          #+#    #+#             */
/*   Updated: 2016/10/08 16:51:35 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <string.h>
# define HEIGHT 700
# define WIDTH 900
# define max 1000
# define MOUSE_ROLL_UP 5
# define MOUSE_ROLL_DOWN 4
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125

typedef	struct	s_draw
{
	char	*fractal;
	void	*m_ptr;
	void	*w_ptr;
	float	zoom;
}				t_draw;

typedef	struct	s_julia
{
	int		iter;
	int		pix_x;
	int		pix_y;
	int		color;
	int		max_iter;
	float	y_dir;
	float	x_dir;
	float	real_c;
	float	imagi_c;
	float	new_real;
	float	new_imagi;
	float	old_real;
	float	old_imagi;
}				t_julia;

typedef	struct	s_mendel
{
	int		i;
	int		x;
	int		y;
	int		color;
	float	pixel_real;
	float	pixel_im;
	float	new_real;
	float	new_imagi;
	float	old_real;
	float	old_im;
}				t_mendel;

int		key_press(int k, t_draw *d);
int     color_palette(int c);
int		mouse_event(int keycode, int x, int y, t_draw *d);
void	draw_sierpinski(void *m, void *w, float zoom);
void    draw_julia(void *m_ptr, void *w_ptr, float zoom);
void    draw_mendelbrot(void *m_ptr, void *w_ptr, float zoom, float x, float y);
void    draw_fractal(void *m_ptr, void *w_ptr, float zoom, char *fract, float x, float y);

#endif
