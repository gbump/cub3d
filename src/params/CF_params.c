#include "../wolf.h"

void	CF_color_adder(t_win *win, int type)
{
	if (type == 'C')
	{
		win->ceil_col += win->f * 65536;
		win->ceil_col += win->s * 256;
		win->ceil_col += win->t;
	}
	else if (type == 'F')
	{
		win->floor_col += win->f * 65536;
		win->floor_col += win->s * 256;
		win->floor_col += win->t;
	}
}

int	put_CF_param_thr(t_win *win)
{
	int	x;

	x = 0;
	while (ft_isdigit(win->map[win->a][win->b]) == 1)
	{
		x *= 10;
		x += win->map[win->a][win->b] - 48;
		win->b++;
	}
	if (x > 255 || x < 0)
		return (-1);
	return (x);
}

int	put_CF_param(t_win *win, char c)
{
	int	x;

	x = 0;
	if (c == 'f' || c == 's')
	{
		while (win->map[win->a][win->b] != ',')
		{
			if (win->map[win->a][win->b] == ' ')
				return (-1);
			x *= 10;
			x += win->map[win->a][win->b] - 48;
			win->b++;
		}
		if (x > 255 || x < 0)
			return (-1);
		win->b++;
		if (skipper(win) == -1)
			return (-1);
	}
	return (x);
}

int	check_CF(t_win *win, int type)
{
	while (win->map[win->a][win->b] != type)
		win->b++;
	win->b++;
	while (ft_isdigit(win->map[win->a][win->b]) != 1)
	{
		if (!(is_whitespace(win->map[win->a][win->b])))
			return (-1);
		win->b++;
	}
	win->f = put_CF_param(win, 'f');
	win->s = put_CF_param(win, 's');
	win->t = put_CF_param_thr(win);
	if (win->f == -1 || win->s == -1 || win->t == -1)
		return (-1);
	while (win->map[win->a][win->b])
	{
		if (win->map[win->a][win->b] != ' ')
			return (-1);
		win->b++;
	}
	CF_color_adder(win, type);
	win->a += 1;
	win->b = 0;
	return (0);
}
