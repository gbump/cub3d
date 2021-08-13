#include "../wolf.h"

void	RayDir(t_win *win)
{
	if (win->rayDirX < 0)
	{
		win->stepX = -1;
		win->sideDistX = (win->rayPosX - win->mapX) * win->deltaDistX;
	}
	else
	{
		win->stepX = 1;
		win->sideDistX = (win->mapX + 1.0 - win->rayPosX) * win->deltaDistX;
	}
	if (win->rayDirY < 0)
	{
		win->stepY = -1;
		win->sideDistY = (win->rayPosY - win->mapY) * win->deltaDistY;
	}
	else
	{
		win->stepY = 1;
		win->sideDistY = (win->mapY + 1.0 - win->rayPosY) * win->deltaDistY;
	}
}

void	Hit(t_win *win)
{
	while (win->hit == 0)
	{
		if (win->sideDistX < win->sideDistY)
		{
			win->sideDistX += win->deltaDistX;
			win->mapX += win->stepX;
			win->side = 0;
		}
		else
		{
			win->sideDistY += win->deltaDistY;
			win->mapY += win->stepY;
			win->side = 1;
		}
		if (win->map[win->mapX][win->mapY] != '0')
			win->hit = 1;
	}
}

void	Side(t_win *win)
{
	if (win->side == 0)
		win->perpWallDist = (win->mapX - win->rayPosX
				+ (1 - win->stepX) / 2) / win->rayDirX;
	else
		win->perpWallDist = (win->mapY - win->rayPosY
				+ (1 - win->stepY) / 2) / win->rayDirY;
	if (win->side == 0)
		win->wall_x = win->rayPosY + win->perpWallDist * win->rayDirY;
	else
		win->wall_x = win->rayPosX + win->perpWallDist * win->rayDirX;
	win->wall_x = 1 - (win->wall_x - floor(win->wall_x));
}

void	add_params(t_win *win)
{
	win->lineHeight = (int)(win->screenh / win->perpWallDist);
	win->drawStart = -win->lineHeight / 2 + win->screenh / 2;
	if (win->drawStart < 0)
		win->drawStart = 0;
	win->drawEnd = win->lineHeight / 2 + win->screenh / 2;
	if (win->drawEnd >= win->screenh)
		win->drawEnd = win->screenh - 1;
	win->tex_x = (int)(win->wall_x * (double)(64));
	if (win->side == 0 && win->rayDirX > 0)
		win->tex_x = 64 - win->tex_x - 1;
	if (win->side == 1 && win->rayDirY < 0)
		win->tex_x = 64 - win->tex_x - 1;
	win->step = 1.0 * 64 / win->lineHeight;
	win->tex_pos = (win->drawStart - win->screenh
			/ 2 + win->lineHeight / 2) * win->step;
}

void	inizialization(t_win *win, int x)
{
	win->cameraX = 2 * x / (double)win->screenw - 1;
	win->rayPosX = win->posX;
	win->rayPosY = win->posY;
	win->rayDirX = win->dirX + win->planeX * win->cameraX;
	win->rayDirY = win->dirY + win->planeY * win->cameraX;
	win->mapX = (int)win->rayPosX;
	win->mapY = (int)win->rayPosY;
	win->deltaDistX = sqrt(1 + (win->rayDirY * win->rayDirY)
			/ (win->rayDirX * win->rayDirX));
	win->deltaDistY = sqrt(1 + (win->rayDirX * win->rayDirX)
			/ (win->rayDirY * win->rayDirY));
	win->hit = 0;
	RayDir(win);
	Hit(win);
	Side(win);
}
