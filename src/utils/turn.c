#include "../wolf.h"

void	turn_left(t_win *win)
{
	double	olddirx;
	double	oldplanex;

	olddirx = win->dirX;
	oldplanex = win->planeX;
	win->dirX = win->dirX * cos(win->rotate) - win->dirY * sin(win->rotate);
	win->dirY = olddirx * sin(win->rotate) + win->dirY * cos(win->rotate);
	win->planeX = win->planeX * cos(win->rotate)
		- win->planeY * sin(win->rotate);
	win->planeY = oldplanex * sin(win->rotate) + win->planeY * cos(win->rotate);
}

void	turn_right(t_win *win)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = win->dirX;
	win->dirX = win->dirX * cos(-win->rotate) - win->dirY * sin(-win->rotate);
	win->dirY = oldDirX * sin(-win->rotate) + win->dirY * cos(-win->rotate);
	oldPlaneX = win->planeX;
	win->planeX = win->planeX * cos(-win->rotate)
		- win->planeY * sin(-win->rotate);
	win->planeY = oldPlaneX * sin(-win->rotate)
		+ win->planeY * cos(-win->rotate);
}
