#include "../wolf.h"

static int	get_sprite_dot(t_win *win, int count, int x, int y)
{
	win->sprites[count] = (t_sprite *)malloc(sizeof(t_sprite));
	if (!win->sprites[count])
		return (-1);
	win->sprites[count]->x = (double)y + 0.5;
	win->sprites[count]->y = (double)x + 0.5;
	win->map[y][x] = '0';
	return (0);
}

int	parse_sprites(t_win *win, int i)
{
	int	count;
	int	j;

	count = 0;
	win->sprites = (t_sprite **)malloc(sizeof(t_sprite *)
			* (win->sprite_count + 1));
	if (!win->sprites)
		return (-1);
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == '2')
			{
				if ((get_sprite_dot(win, count, j, i)) == -1)
					return (-1);
				count++;
			}
			j++;
		}
		i++;
	}
	win->sprites[count] = NULL;
	return (0);
}
