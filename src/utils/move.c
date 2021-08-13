#include "../wolf.h"

void	move_forth(t_win *win)
{
	if (win->map[(int)(win->posX
			+ win->dirX * MOVESPEED)][(int)win->posY] == '0')
		win->posX += win->dirX * MOVESPEED;
	if (win->map[(int)win->posX][(int)(win->posY
		+ win->dirY * MOVESPEED)] == '0')
		win->posY += win->dirY * MOVESPEED;
}

void	move_back(t_win *win)
{
	if (win->map[(int)(win->posX
			- win->dirX * MOVESPEED)][(int)win->posY] == '0')
		win->posX -= win->dirX * MOVESPEED;
	if (win->map[(int)win->posX][(int)(win->posY
		- win->dirY * MOVESPEED)] == '0')
		win->posY -= win->dirY * MOVESPEED;
}

void	move_left(t_win *win)
{
	if (win->map[(int)(win->posX
			- win->planeX * MOVESPEED)][(int)win->posY] == '0')
		win->posX -= win->planeX * MOVESPEED;
	if (win->map[(int)win->posX][(int)(win->posY
		- win->planeY * MOVESPEED)] == '0')
		win->posY -= win->planeY * MOVESPEED;
}

void	move_right(t_win *win)
{
	if (win->map[(int)(win->posX
			+ win->planeX * MOVESPEED)][(int)win->posY] == '0')
		win->posX += win->planeX * MOVESPEED;
	if (win->map[(int)win->posX][(int)(win->posY
		+ win->planeY * MOVESPEED)] == '0')
		win->posY += win->planeY * MOVESPEED;
}
