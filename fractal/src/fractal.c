/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:42:33 by emsimang          #+#    #+#             */
/*   Updated: 2016/10/08 06:12:40 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <complex.h>
#include <string.h>
#define	HEIGHT 700
#define WIDTH 900
#define max 1000
#define KEY_ESC 53
#define KEY_UP 126
#define KEY_DOWN 125

int		color_palette(int c);
void	draw_julia(void *m_ptr, void *w_ptr, float zoom);
void	draw_mendelbrot(void *m_ptr, void *w_ptr, float zoom);
void	draw_fractal(void *m_ptr, void *w_ptr, float zoom, char *fract);

typedef	struct	s_draw
{
	float	zoom;
	void	*m_ptr;
	void	*w_ptr;
	char	*fractal;
}				t_draw;

int	mouse_event(int mouse)
{
	return (1);
}

int	key_press(int keycode, t_draw *draw)
{
	int	scale;

	scale = 20;
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP)
		draw->zoom += scale;
	else if (keycode == KEY_DOWN)
		draw->zoom -= scale;
	draw_fractal(draw->m_ptr, draw->w_ptr, draw->zoom, draw->fractal);
	return (1);
}

void	draw_julia(void *m_ptr, void *w_ptr, float zoom)
{
	int		i;
	int		y;
	int		x;
	int		color;
	int		max_iter;
	float	real_c;
	float	imag_c;           
	float	new_real;
	float	new_imagi;
	float	old_real;
	float	old_im;
	float	x_dir = 0;
	float	y_dir = 0;

	y = 0;
	real_c = -0.6;
	imag_c = 0.427015;
	max_iter = 500;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			new_real = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH);
			new_imagi = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT);
			i = 0;
			while ((new_real * new_real + new_imagi * new_imagi) < 4 && i < max_iter)
			{
				old_real = new_real;
				old_im = new_imagi;
				new_real = old_real * old_real - old_im * old_im + real_c;
				new_imagi = 2 * old_real * old_im + imag_c;
				i++;
			}
			if (i < max_iter)
			{
				if (i >= 0 && i < 200)
					color = 0x000;
				else if (i >= 200 && i < 400)
					color = 0x4fcf00;
				else if (i >= 400 && i < 600)
					color = 0xc6ff00;
				else if (i >= 600 && i < 800)
					color = 0xbbed57;
				else
					color = 0xffeb3b;
				mlx_pixel_put(m_ptr, w_ptr, x, y, color_palette(i));
			}
			else
				mlx_pixel_put(m_ptr, w_ptr, x, y, 0x000);
			x++;
		}
		y++;
	}
}

int	color_palette(int color)
{
	int	size;
	int palette[] = {7473449,7539499,7605805,7737391,7803697,7935284,8001590,8133176,8199482,8331325,8397375,8529217,8595267,
					 8727109,8793160,8925002,8991308,9057358,9189201,9255251,9387093,9453143,9584986,9651036,9782878,9849184,
					 9980770,10047077,10178663,10244969,10376555,10442862,10574704,10640754,10707060,10838647,10904953,11036539,
					 11102845,11234431,11300738,11432580,11498630,11630472,11696523,11828365,11894415,12026257,12092564,12158614,
					 12290456,12356506,12488348,12554399,12686241,12752291,12884133,12950440,13082026,13148332,13279918,13346224,
					 13477811,13544117,13675959,13742009,13808316,13939902,14006208,14137794,14204101,14335687,14401993,14533835,
					 14599885,14731728,14797778,14929620,14995670,15127513,15193819,15259869,15391711,15457762,15589604,15655654,
					 15787496,15853546,15985389,16051695,16183281,16249587,16381174,16447480,16579066,16645372,10799852,10668009,
					 10536423,10404836,10338786,10207199,10075613,10009562,9877976,9746389,9614547,9548496,9416910,9285324,9219273,
					 9087687,8956100,8824514,8758463,8626877,8495034,8428984,8297397,8165811,8099761,7968174,7836588,7705001,7638951,
					 7507108,7375522,7309471,7177885,7046298,6914712,6848661,6717075,6585489,6519438,6387596,6256009,6124423,6058372,
					 5926786,5795199,5729149,5597562,5465976,5399926,5268083,5136497,5004910,4938860,4807273,4675687,4609636,4478050,
					 4346463,4214621,4148570,4016984,3885398,3819347,3687761,3556174,3424588,3358537,3226951,3095108,3029058,2897471,
					 2765885,2699835,2568248,2436662,2305075,2239025,2107182,1975596,1909545,1777959,1646372,1514786,1448735,1317149,
					 1185563,1119512,987670,856083,724497,658446,526860,395273,329223,197636,66050};
	size = sizeof(palette) / sizeof(int);
	return (palette[color % size]);
}

void	draw_mendelbrot(void *m_ptr, void *w_ptr, float zoom)
{
	int		i;
	int		x;
	int		y;
	int		color;
  	float 	pixel_real;
	float	pixel_im;
  	float	new_real;
	float	new_imagi;
	float	old_real;
	float	old_im;
  	float 	x_dir = -0.5;
	float	y_dir = 0;

	y = 0;
  	while (y < HEIGHT)
	{
		x = 0;
	  	while (x < WIDTH)
	 	 {
	  		pixel_real = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + x_dir;
	  		pixel_im = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + y_dir;
	  		new_real = new_imagi = old_real = old_im = 0;
	  		i = 0;
	  		while ((new_real * new_real + new_imagi * new_imagi) < 4 && i < max)
	 	 	{
	  			old_real = new_real;
	  			old_im = new_imagi;
	  			new_real = old_real * old_real - old_im * old_im + pixel_real;
	  			new_imagi = 2 * old_real * old_im + pixel_im;
	  			i++;
	  		}
			if (i < max)
				mlx_pixel_put(m_ptr, w_ptr, x, y, color_palette(i));
			else
				mlx_pixel_put(m_ptr, w_ptr, x, y, (int)sin(color_palette(i)));
			x++;
		 }
		y++;
	}
}

void	draw_sierpinski(void *m_ptr, void *w_ptr, float zoom)
{

	int		x;
	int		y;

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
				
				!((x / 81) % 3 == 1 && (y / 81) % 3 == 1)

				)
				mlx_pixel_put(m_ptr, w_ptr, x, y, color_palette(x + y));
			x++;
		}
		y++;
	}
}

void	draw_fractal(void *m_ptr, void *w_ptr, float zoom, char *fract)
{
	if (strcmp(fract, "julia") == 0)
		draw_julia(m_ptr, w_ptr, zoom);
	else if (strcmp(fract, "mendelbrot") == 0)
		draw_mendelbrot(m_ptr, w_ptr, zoom);
	else if (strcmp(fract, "sierpinski") == 0)
		draw_sierpinski(m_ptr, w_ptr, zoom);
	else
		return;
}

int main(int ac, char **av)
{
	t_draw	draw;

	if (ac == 2)
	{
		draw.zoom = 1.0f;
		draw.fractal = av[1];
		draw.m_ptr = mlx_init();
		draw.w_ptr = mlx_new_window(draw.m_ptr, WIDTH, HEIGHT, draw.fractal);
		draw_fractal(draw.m_ptr, draw.w_ptr, draw.zoom, draw.fractal);
		mlx_key_hook(draw.w_ptr, &key_press, &draw);
		mlx_mouse_hook(draw.w_ptr, &mouse_event, &draw);
		mlx_loop(draw.m_ptr);
	}
	else
		printf("parameters: julia | mendelbrot | sierpinski\n");
	return (0);
}
