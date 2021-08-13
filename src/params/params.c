#include "../wolf.h"

/*int	check_params_R_C(t_win *win)
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
	else if (win->map[win->a][win->b] == 'C')
	{
		win->ceil_col = 0;
		if (whats_map(win, 'C') == -1 || (check_CF(win, 'C')) == -1)
		{
			error_print(7, win);
			return (-1);
		}
		win->params_count++;
	}
	return (0);
}

int	check_params_F_NO(t_win *win)
{
	if (win->map[win->a][win->b] == 'F')
	{
		win->floor_col = 0;
		if (whats_map(win, 'F') == -1 || (check_CF(win, 'F')) == -1)
		{
			error_print(8, win);
			return (-1);
		}
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
}*/

int	sum_check_params(t_win *win)
{
	if (check_params_R_C(win) == -1)
		return (-1);
	if (check_params_F_NO(win) == -1)
		return (-1);
	if (check_params_SO_WE(win) == -1)
		return (-1);
	if (check_params_EA_S(win) == -1)
		return (-1);
	return (0);
}

int	CP_sum(t_win *win, int count_param)
{
	while (win->map[win->a][win->b])
	{
		if (sum_check_params(win) == -1)
			return (-1);
		else if (!(is_whitespace(win->map[win->a][win->b]))
					&& count_param == win->params_count)
		{
			if (!(win->map[win->a][win->b]))
				break ;
			error_print(14, win);
			return (-1);
		}
		if (win->params_count == 8)
			break ;
		win->b++;
	}
	return (0);
}

int	check_params(t_win *win)
{
	int	count_param;

	win->a = 0;
	win->params_count = 0;
	count_param = 0;
	win->fl = 0;
	win->cl = 0;
	while (win->map[win->a])
	{
		win->b = 0;
		if (CP_sum(win, count_param) == -1)
			return (-1);
		if (count_param == win->params_count)
			win->a++;
		count_param = win->params_count;
		if (win->params_count == 8)
			break ;
	}
	if (win->params_count != 8)
	{
		error_print(5, win);
		return (-1);
	}
	return (0);
}

/*int	NO_malloc_prt1(int t1, int t2, int i, t_win *win)
{
	if (t1 == 'N' && t2 == 'O')
	{
		win->no = (char *)malloc(sizeof(char) * (i + 1));
		if (!(win->no))
			return (-1);
	}
	else if (t1 == 'S' && t2 == 'O')
	{
		win->so = (char *)malloc(sizeof(char) * (i + 1));
		if (!(win->so))
			return (-1);
	}
	return (0);
}

int	NO_malloc_prt2(int t1, int t2, int i, t_win *win)
{
	if (t1 == 'W' && t2 == 'E')
	{
		win->we = (char *)malloc(sizeof(char) * (i + 1));
		if (!(win->we))
			return (-1);
	}
	else if (t1 == 'E' && t2 == 'A')
	{
		win->ea = (char *)malloc(sizeof(char) * (i + 1));
		if (!(win->ea))
			return (-1);
	}
	else if (t1 == 'S' && t2 == ' ')
	{
		win->sprite = (char *)malloc(sizeof(char) * (i + 1));
		if (!(win->sprite))
			return (-1);
	}
	return (0);
}

void	NO_add_texture_prt1(int t1, int t2, t_win *win)
{
	int	i;

	i = -1;
	if (t1 == 'N' && t2 == 'O')
	{
		while (win->texx[++i] != '\0')
			win->no[i] = win->texx[i];
		win->no[i] = '\0';
	}
	else if (t1 == 'S' && t2 == 'O')
	{
		while (win->texx[++i] != '\0')
			win->so[i] = win->texx[i];
		win->so[i] = '\0';
	}
}

void	NO_add_texture_prt2(int t1, int t2, t_win *win)
{
	int	i;

	i = -1;
	if (t1 == 'W' && t2 == 'E')
	{
		while (win->texx[++i] != '\0')
			win->we[i] = win->texx[i];
		win->we[i] = '\0';
	}
	else if (t1 == 'E' && t2 == 'A')
	{
		while (win->texx[++i] != '\0')
			win->ea[i] = win->texx[i];
		win->ea[i] = '\0';
	}
	else if (t1 == 'S' && t2 == ' ')
	{
		while (win->texx[++i] != '\0')
			win->sprite[i] = win->texx[i];
		win->sprite[i] = '\0';
	}
}*/

int	NO_adder(t_win *win)
{
	int	i;

	i = 0;
	while (!(is_whitespace(win->map[win->a][win->b]))
			&& win->map[win->a][win->b])
	{
		win->texx[i] = win->map[win->a][win->b];
		i++;
		win->b++;
	}
	win->texx[i] = '\0';
	return (i);
}

int	check_NO(t_win *win, int t1, int t2)
{
	int	i;

	while (win->map[win->a][win->b] != t1)
		win->b++;
	win->b++;
	if ((win->map[win->a][win->b] == t2) || (t2 != ' '))
		win->b++;
	while ((is_whitespace(win->map[win->a][win->b])))
		win->b++;
	i = NO_adder(win);
	if (NO_malloc_prt1(t1, t2, i, win) == -1)
		return (-1);
	else if (NO_malloc_prt2(t1, t2, i, win) == -1)
		return (-1);
	while (win->map[win->a][win->b])
	{
		if (!(is_whitespace(win->map[win->a][win->b])))
			return (-1);
		win->b++;
	}
	NO_add_texture_prt1(t1, t2, win);
	NO_add_texture_prt2(t1, t2, win);
	win->a += 1;
	win->b = 0;
	return (0);
}

/*int	skipper(t_win *win)
{
	while (ft_isdigit(win->map[win->a][win->b]) == 0)
	{
		if (win->map[win->a][win->b] == ' ')
			win->b++;
		else
			return (-1);
	}
	return (0);
}*/

/*int	CF_plus(t_win *win)
{
	while (win->map[win->a][win->b] != ',')
	{
		win->f *= 10;
		win->f += win->map[win->a][win->b] - 48;
		win->b++;
	}
	if (win->map[win->a][win->b] == ','
			&& (ft_isdigit(win->map[win->a][win->b + 1]) == 0
			&& win->map[win->a][win->b + 1] != ' '))
		return (-1);
	else
		win->b++;
	if (win->f > 255 || win->f < 0)
		return (-1);
	if (skipper(win) == -1)
		return (-1);
	while (win->map[win->a][win->b] != ',')
	{
		win->s *= 10;
		win->s += win->map[win->a][win->b] - 48;
		win->b++;
	}
	return (0);
}

int	CF_frst_part(t_win *win)
{
	if (CF_plus(win) == -1)
		return (-1);
	if (win->map[win->a][win->b] == ','
			&& ft_isdigit(win->map[win->a][win->b + 1]) == 0
			&& win->map[win->a][win->b + 1] != ' ')
		return (-1);
	else
		win->b++;
	if (win->s > 255 || win->s < 0)
		return (-1);
	if (skipper(win) == -1)
		return (-1);
	while (ft_isdigit(win->map[win->a][win->b]) == 1)
	{
		win->t *= 10;
		win->t += win->map[win->a][win->b] - 48;
		win->b++;
	}
	if (win->t > 255 || win->t < 0)
		return (-1);
	return (0);
}

int	CF_adder(t_win *win)
{
	win->f = 0;
	win->s = 0;
	win->t = 0;
	if (ft_isdigit(win->map[win->a][win->b]) == 1)
	{
		if (CF_frst_part(win) == -1)
			return (-1);
	}
	return (0);
}

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

int	check_CF(t_win *win, int type)
{
	while (win->map[win->a][win->b] != type)
		win->b++;
	win->b++;
	while (ft_isdigit(win->map[win->a][win->b]) == 0)
	{
		if (!(is_whitespace(win->map[win->a][win->b])))
			return (-1);
		win->b++;
	}
	if (CF_adder(win) == -1)
		return (-1);
	while (win->map[win->a][win->b])
	{
		if (!(is_whitespace(win->map[win->a][win->b])))
			return (-1);
		win->b++;
	}
	CF_color_adder(win, type);
	win->a += 1;
	win->b = 0;
	return (0);
}*/

/*void	R_plus(t_win *win)
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
}*/
