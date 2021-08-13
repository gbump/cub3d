#include "../wolf.h"

void	texture_print(t_win *win, int x, t_tex *tex)
{
	int	pixel_num;
	int	new_draw_start;

	new_draw_start = win->drawStart;
	while (new_draw_start < win->drawEnd)
	{
		win->tex_y = (int)win->tex_pos & (64 - 1);
		win->tex_pos += win->step;
		pixel_num = 64 * win->tex_y + win->tex_x;
		win->color = ((int *)tex->line)[pixel_num];
		my_mlx_pixel_put(win, x, new_draw_start, win->color);
		new_draw_start++;
	}
}

static int	textute_mistakes_prt2(t_win *win)
{
	if (texture_east(win) == -1)
	{
		error_print(12, win);
		return (-1);
	}
	if (texture_west(win) == -1)
	{
		error_print(11, win);
		return (-1);
	}
	if (texture_sprite(win) == -1)
	{
		error_print(13, win);
		return (-1);
	}
	return (0);
}

int	textute_mistakes_prt1(t_win *win)
{
	if (texture_north(win) == -1)
	{
		error_print(9, win);
		return (-1);
	}
	if (texture_south(win) == -1)
	{
		error_print(10, win);
		return (-1);
	}
	if (textute_mistakes_prt2(win) == -1)
		return (-1);
	return (0);
}
