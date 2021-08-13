#include "../wolf.h"

void	calc_sprite_distance(t_win *win)
{
	int			count;

	count = 0;
	while (win->sprites[count])
	{
		win->sprites[count]->distance = ((win->posX - win->sprites[count]->x)
				* (win->posX - win->sprites[count]->x)
				+ (win->posY - win->sprites[count]->y)
				* (win->posY - win->sprites[count]->y));
		count++;
	}
}

void	sort_sprites(t_sprite **sprites, int num)
{
	int			i;
	int			j;
	t_sprite	*save;

	if (num == 0)
		return ;
	i = 0;
	while (i < num - 1)
	{
		j = i + 1;
		while (j < num)
		{
			if (sprites[i]->distance < sprites[j]->distance)
			{
				save = sprites[i];
				sprites[i] = sprites[j];
				sprites[j] = save;
			}
			j++;
		}
		i++;
	}
}
