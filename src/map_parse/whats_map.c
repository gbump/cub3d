#include "../wolf.h"

int	whats_mapNO(t_win *win, int c, int d)
{
	int	j;

	j = 0;
	if ((c == 'N' && d == 'O') || (c == 'S' && d == 'O')
		|| (c == 'W' && d == 'E') || (c == 'E' && d == 'A'))
	{
		j = 0;
		while (win->map[win->a][j] != c)
		{
			if (!(is_whitespace(win->map[win->a][j])))
				return (-1);
			j++;
		}
		if (win->map[win->a][j] == c && win->map[win->a][j + 1] == d
			&& !(is_whitespace(win->map[win->a][j + 2])))
			return (-1);
		j += 2;
	}
	return (0);
}

int	whats_map_R(t_win *win)
{
	int	j;

	j = 0;
	while (win->map[win->a][j] != 'R')
	{
		if (!(is_whitespace(win->map[win->a][j])))
			return (-1);
		j++;
	}
	if (win->map[win->a][j] == 'R'
		&& !(is_whitespace(win->map[win->a][j + 1])))
		return (-1);
	j++;
	while (win->map[win->a][j])
	{
		if (!(ft_isdigit(win->map[win->a][j]))
			&& !(is_whitespace(win->map[win->a][j])))
			return (-1);
		j++;
	}
	return (0);
}

int	whats_map_CF(t_win *win, int c)
{
	int	j;

	j = 0;
	while (win->map[win->a][j] != c)
	{
		if (!(is_whitespace(win->map[win->a][j])))
			return (-1);
		j++;
	}
	if (win->map[win->a][j] == c && !(is_whitespace(win->map[win->a][j + 1])))
		return (-1);
	j++;
	while (win->map[win->a][j])
	{
		if (!(ft_isdigit(win->map[win->a][j]))
			&& !(is_whitespace(win->map[win->a][j]))
			&& win->map[win->a][j] != ',')
			return (-1);
		j++;
	}
	return (0);
}

int	whats_map_S(t_win *win, int c)
{
	int	j;

	j = 0;
	while (win->map[win->a][j] != c)
	{
		if (!(is_whitespace(win->map[win->a][j])))
			return (-1);
		j++;
	}	
	if (win->map[win->a][j] == c
		&& !(is_whitespace(win->map[win->a][j + 1])))
		return (-1);
	return (0);
}

int	whats_map(t_win *win, int c)
{
	int	j;

	j = 0;
	if (c == 'R')
	{
		if (whats_map_R(win) == -1)
			return (-1);
	}
	if (c == 'F' || c == 'C')
	{
		if (whats_map_CF(win, c) == -1)
			return (-1);
	}
	if (c == 'S')
	{
		if (whats_map_S(win, c) == -1)
			return (-1);
	}
	return (0);
}
