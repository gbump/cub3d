#include "../wolf.h"

int	check_params_R_C(t_win *win)
{
	if (win->map[win->a][win->b] == 'R')
	{
		if (whats_map(win, 'R') == -1 || check_R(win) == -1)
		{
			error_print(6, win);
			return (-1);
		}
		win->params_count++;
	}
	else if (win->cl == 0 && win->map[win->a][win->b] == 'C')
	{
		win->ceil_col = 0;
		if (whats_map(win, 'C') == -1 || (check_CF(win, 'C')) == -1)
		{
			error_print(7, win);
			return (-1);
		}
		win->cl++;
		win->params_count++;
	}
	return (0);
}

int	check_params_F_NO(t_win *win)
{
	if (win->fl == 0 && win->map[win->a][win->b] == 'F')
	{
		win->floor_col = 0;
		if (whats_map(win, 'F') == -1 || (check_CF(win, 'F')) == -1)
		{
			error_print(8, win);
			return (-1);
		}
		win->fl++;
		win->params_count++;
	}
	else if (win->map[win->a][win->b] == 'N'
			&& win->map[win->a][win->b + 1] == 'O')
	{
		if (whats_mapNO(win, 'N', 'O') == -1 || (check_NO(win, 'N', 'O')) == -1)
		{
			error_print(9, win);
			return (-1);
		}
		win->params_count++;
	}
	return (0);
}

int	check_params_SO_WE(t_win *win)
{
	if (win->map[win->a][win->b] == 'S' && win->map[win->a][win->b + 1] == 'O')
	{
		if (whats_mapNO(win, 'S', 'O') == -1 || (check_NO(win, 'S', 'O')) == -1)
		{
			error_print(10, win);
			return (-1);
		}
		win->params_count++;
	}
	else if (win->map[win->a][win->b] == 'W'
			&& win->map[win->a][win->b + 1] == 'E')
	{
		if (whats_mapNO(win, 'W', 'E') == -1 || (check_NO(win, 'W', 'E')) == -1)
		{
			error_print(11, win);
			return (-1);
		}
		win->params_count++;
	}
	return (0);
}

int	check_params_EA_S(t_win *win)
{
	if (win->map[win->a][win->b] == 'E' && win->map[win->a][win->b + 1] == 'A')
	{
		if (whats_mapNO(win, 'E', 'A') == -1 || (check_NO(win, 'E', 'A')) == -1)
		{
			error_print(12, win);
			return (-1);
		}
		win->params_count++;
	}
	else if (win->map[win->a][win->b] == 'S'
			&& is_whitespace(win->map[win->a][win->b + 1]))
	{
		if (whats_map(win, 'S') == -1 || (check_NO(win, 'S', ' ')) == -1)
		{
			error_print(13, win);
			return (-1);
		}
		win->params_count++;
	}
	return (0);
}
