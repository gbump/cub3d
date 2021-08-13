#include "../wolf.h"

void	combination(t_win *win, double *d_buf, t_tex *tex)
{
	int		x;

	x = 0;
	while (x < win->screenw)
	{
		inizialization(win, x);
		if (win->side == 1)
		{
			if (win->stepY > 0)
				tex = &win->texture.south;
			if (win->stepY < 0)
				tex = &win->texture.north;
		}
		if (win->side == 0)
		{
			if (win->stepX > 0)
				tex = &win->texture.east;
			if (win->stepX < 0)
				tex = &win->texture.west;
		}
		add_params(win);
		texture_print(win, x, tex);
		d_buf[x] = win->perpWallDist;
		x++;
	}
}

int	draw(t_win *win)
{
	double	*d_buf;
	t_tex	*tex;

	tex = NULL;
	check_press(win);
	background(win);
	d_buf = (double *)malloc(sizeof(double) * (win->screenw + 1));
	if (!d_buf)
	{
		error_print(19, win);
		all_free(win);
		return (-1);
	}
	combination(win, d_buf, tex);
	if (spr1(win, d_buf) == -1)
		all_free(win);
	free (d_buf);
	mlx_put_image_to_window(win->mlx, win->win, win->image, 0, 0);
	return (0);
}

int	adder(t_win *win)
{
	win->tex_width = 64;
	win->tex_height = 64;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->screenw, win->screenh, "cub3D");
	create_image(win);
	win->rotate = 0.04;
	if (textute_mistakes_prt1(win) == -1)
	{
		exit_mistakes(win);
		return (-1);
	}
	return (0);
}

int	write_to_image(t_win *win, int save)
{
	if (save == 3)
	{
		if (adder(win) == -1)
			return (-1);
		draw(win);
		if (screenshot(win) == -1)
		{
			exit_mistakes(win);
			return (-1);
		}
		exit_mistakes(win);
		return (0);
	}
	if (adder(win) == -1)
		return (-1);
	mlx_do_key_autorepeatoff(win->mlx);
	mlx_hook(win->win, 17, 0, all_free, win);
	mlx_hook(win->win, 3, 0, go_up, win);
	mlx_hook(win->win, 2, 0, go_down, win);
	mlx_loop_hook(win->mlx, draw, win);
	mlx_loop(win->mlx);
	return (0);
}
