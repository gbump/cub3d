#include "../wolf.h"

void	R_plus(t_win *win)
{
	int	i;

	i = 0;
	while (win->map[win->a][win->b] && win->screenw != 0)
	{
		if (win->screenh >= win->max_screenh)
		{
			win->screenh = win->max_screenh;
			i = 1;
		}
		if (i == 0 && ft_isdigit(win->map[win->a][win->b]))
		{
			if (win->screenh == -1)
				win->screenh = 0;
			win->screenh *= 10;
			win->screenh += win->map[win->a][win->b] - 48;
		}
		else if ((win->screenh != -1 && !(ft_isdigit(win->map[win->a][win->b])))
				|| (win->map[win->a][win->b] == '\n'))
			break ;
		win->b++;
	}
}

void	R_adder(t_win *win)
{
	int	i;

	i = 0;
	while (win->map[win->a][win->b])
	{
		if (win->screenw > win->max_screenw)
		{
			win->screenw = win->max_screenw;
			i = 1;
		}	
		if (i == 0 && ft_isdigit(win->map[win->a][win->b]))
		{
			if (win->screenw == -1)
				win->screenw = 0;
			win->screenw *= 10;
			win->screenw += win->map[win->a][win->b] - 48;
		}
		else if ((win->screenw != -1 && !(ft_isdigit(win->map[win->a][win->b])))
				|| (win->map[win->a][win->b] == '\n'))
			break ;
		win->b++;
	}
	R_plus(win);
}

int	check_R(t_win *win)
{
	int	after;

	win->screenw = -1;
	win->screenh = -1;
	after = 0;
	mlx_get_screen_size(&win->max_screenw, &win->max_screenh);
	R_adder(win);
	if ((win->screenw == 0 && win->screenh == 0)
		|| (win->screenw == -1 || win->screenh == -1))
		return (-1);
	while (win->map[win->a][win->b])
	{
		if (!(is_whitespace(win->map[win->a][win->b])))
			return (-1);
		win->b++;
	}
	win->a += 1;
	win->b = 0;
	return (0);
}
