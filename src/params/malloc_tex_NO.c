#include "../wolf.h"

int	NO_malloc_prt1(int t1, int t2, int i, t_win *win)
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
}
