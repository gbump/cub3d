#include "../wolf.h"

/*int	whats_mapNO(t_win *win, int c, int d)
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
	if (c == 'C' || c == 'F')
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
}*/

/*int	dop_circs_prt2(t_win *win, int i, int j)
{
	if (search_signs(i - 1, j, win) == 0)
		return (-1);
	if (j > win->prew - 1 && i != win->extra)
		return (-1);
	if (j > win->aftw - 1 && i != win->height - 1)
		return (-1);
	if (win->map[i][j] == 'N' || win->map[i][j] == 'S'
		|| win->map[i][j] == 'W' || win->map[i][j] == 'E')
		win->NSWE_counter++;
	return (0);
}

int	dop_circs_prt1(t_win *win, int i, int j)
{
	if (win->width - 1 == j || win->height - 1 == i
		|| win->extra == i || j == 0)
		return (-1);
	if (search_signs(i, j - 1, win) == 0)
		return (-1);
	if (search_signs(i, j + 1, win) == 0)
		return (-1);
	if (search_signs(i + 1, j, win) == 0)
		return (-1);
	return (0);
}*/

int	string_parsing(t_win *win, int i, int j)
{
	while (win->map[i][j])
	{
		if (search_signs(i, j, win) == 0 && !(is_whitespace(win->map[i][j])))
		{
			error_print(15, win);
			return (-1);
		}
		if ((win->map[i][j] == 'N' || win->map[i][j] == 'S'
			|| win->map[i][j] == 'W' || win->map[i][j] == 'E'
			|| win->map[i][j] == '2' || win->map[i][j] == '0'))
		{
			if ((dop_circs_prt1(win, i, j)) == -1)
			{
				error_print(15, win);
				return (-1);
			}
			if ((dop_circs_prt2(win, i, j)) == -1)
			{
				error_print(15, win);
				return (-1);
			}
		}
		j++;
	}
	return (0);
}

int	map_ending(t_win *win, int i, int j)
{
	win->extra = i;
	win->counth = win->height - 1;
	while (win->map[i] && win->counth >= 0)
	{
		j = 0;
		win->prew = win->width;
		win->width = 0;
		win->aftw = 0;
		while (win->map[i][win->width])
			win->width++;
		while (i + 1 != win->height && win->map[i][win->aftw])
			win->aftw++;
		if (string_parsing(win, i, j) == -1)
			return (-1);
		win->counth--;
		i++;
	}
	if (win->NSWE_counter != 1)
	{
		error_print(17, win);
		return (-1);
	}
	return (0);
}

int	map_start(t_win *win)
{
	win->NSWE_counter = 0;
	while (win->map[win->a])
	{
		win->b = 0;
		while (win->map[win->a][win->b])
		{
			if (!(is_whitespace(win->map[win->a][win->b]))
				&& win->map[win->a][win->b] != '1')
			{
				error_print(15, win);
				return (-1);
			}
			if (win->map[win->a][win->b] == '1')
				break ;
			win->b++;
		}
		if (win->map[win->a][win->b] == '1')
			break ;
		win->a++;
	}
	return (0);
}

void	map_middle(t_win *win)
{
	int	adder;

	adder = 0;
	while (win->height - win->a != 0)
	{
		win->b = 0;
		adder = 0;
		while (win->map[win->height - 1][win->b])
		{
			if (is_whitespace(win->map[win->height - 1][win->b]) == 1)
				adder++;
			win->b++;
		}
		if (adder == win->b)
			win->height--;
		else
			break ;
	}
}

int	check_map(t_win *win)
{
	int	i;
	int	j;

	if ((map_start(win)) == -1)
		return (-1);
	win->height = win->a;
	while (win->map[win->height])
		win->height++;
	map_middle(win);
	i = win->height - 1;
	while (win->map[i] && i >= win->a)
	{
		j = 0;
		while (win->map[i][j])
			j++;
		if (j == 0)
		{
			error_print(16, win);
			return (-1);
		}
		i--;
	}
	if ((map_ending(win, win->a, win->b)) == -1)
		return (-1);
	return (0);
}
