#include "../wolf.h"

int	all_free(t_win *win)
{
	int	count;

	count = win->sprite_count;
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	exit_mistakes(win);
	printf("%s\n", "byee");
	exit(0);
	return (0);
}

static void	sprites_free(t_win *win)
{
	size_t	count;

	count = 0;
	if (win->sprites)
	{
		while (win->sprites[count])
		{
			free(win->sprites[count]);
			win->sprites[count++] = NULL;
		}
		free(win->sprites);
		win->sprites = NULL;
	}
}

static void	map_free(t_win *win)
{
	size_t	count;

	count = 0;
	if (win->map)
	{
		while (win->map[count])
		{
			free(win->map[count]);
			win->map[count++] = NULL;
		}
		free(win->map);
		win->map = NULL;
	}
}

void	exit_mistakes(t_win *win)
{
	sprites_free(win);
	if (win->sprites)
		free(win->sprites);
	if (win->no)
		free(win->no);
	if (win->so)
		free(win->so);
	if (win->ea)
		free(win->ea);
	if (win->we)
		free(win->we);
	if (win->sprite)
		free(win->sprite);
	if (win)
		free(win);
	map_free(win);
}
