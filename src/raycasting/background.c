#include "../wolf.h"

static void	floor_color(t_win *win, int y)
{
	int	x;

	x = 0;
	while (y < win->screenh)
	{
		x = 0;
		while (x < win->screenw)
		{
			my_mlx_pixel_put(win, x, y, win->floor_col);
			x++;
		}
		y++;
	}
}

int	background(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < win->screenh / 2)
	{
		x = 0;
		while (x < win->screenw)
		{
			my_mlx_pixel_put(win, x, y, win->ceil_col);
			x++;
		}
		y++;
	}
	floor_color(win, y);
	return (0);
}
