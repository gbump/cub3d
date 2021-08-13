#include "wolf.h"

static void	img_to_bmp(t_win *win, int fd)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < win->screenh)
	{
		x = 0;
		while (x < win->screenw)
		{
			color = *(int *)(win->line + (y * win->line_l
						+ x * (win->bpp / 8)));
			write(fd, &color, 4);
			x++;
		}
		y++;
	}
}

static void	make_bitmap(t_win *win, int fd)
{
	char	bitmap[54];
	int		i;

	i = 0;
	while (i < 54)
	{
		bitmap[i] = 0;
		bitmap[0] = 'B';
		bitmap[1] = 'M';
		bitmap[2] = win->screenh * win->screenw * 4 + 54;
		bitmap[10] = 54;
		bitmap[14] = 40;
		bitmap[18] = win->screenw;
		bitmap[19] = win->screenw >> 8;
		bitmap[20] = win->screenw >> 16;
		bitmap[21] = win->screenw >> 24;
		bitmap[22] = -win->screenh;
		bitmap[23] = -win->screenh >> 8;
		bitmap[24] = -win->screenh >> 16;
		bitmap[25] = -win->screenh >> 24;
		bitmap[26] = 1;
		bitmap[28] = 32;
		i++;
	}
	write(fd, bitmap, 54);
}

int	screenshot(t_win *win)
{
	int	fd;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR);
	if (!fd)
	{
		error_print(20, win);
		return (-1);
	}
	make_bitmap(win, fd);
	img_to_bmp(win, fd);
	close(fd);
	return (0);
}
