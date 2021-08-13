#include "../wolf.h"

int	dop_circs_prt2(t_win *win, int i, int j)
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
}
