#include "../wolf.h"

/*static int	get_sprite_dot(t_win *win, int count, int x, int y)
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
}*/

/*static void	calc_sprite_distance(t_win *win)
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

static void	sort_sprites(t_sprite **sprites, int num)
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
}*/

void	draw_XY(t_spr_value *spr_value, t_win *win)
{
	spr_value->drawStartY = -spr_value->spriteHeight / 2
		+ win->screenh / 2 + spr_value->vMoveScreen;
	if (spr_value->drawStartY < 0)
		spr_value->drawStartY = 0;
	spr_value->drawEndY = spr_value->spriteHeight / 2
		+ win->screenh / 2 + spr_value->vMoveScreen;
	if (spr_value->drawEndY >= win->screenh)
		spr_value->drawEndY = win->screenh - 1;
	spr_value->spriteWidth = abs((int)(win->screenh
				/ (spr_value->transformY)));
	spr_value->drawStartX = -spr_value->spriteWidth / 2
		+ spr_value->spriteScreenX;
	if (spr_value->drawStartX < 0)
		spr_value->drawStartX = 0;
	spr_value->drawEndX = spr_value->spriteWidth / 2 + spr_value->spriteScreenX;
	if (spr_value->drawEndX >= win->screenw)
		spr_value->drawEndX = win->screenw - 1;
}

void	assign_value(t_win *win, int i, t_spr_value *spr_value)
{
	spr_value->spriteX = win->sprites[i]->x - win->posX;
	spr_value->spriteY = win->sprites[i]->y - win->posY;
	spr_value->invDet = 1.0 / (win->planeX * win->dirY
			- win->dirX * win->planeY);
	spr_value->transformX = spr_value->invDet * (win->dirY * spr_value->spriteX
			- win->dirX * spr_value->spriteY);
	spr_value->transformY = spr_value->invDet
		* (-win->planeY * spr_value->spriteX
			+ win->planeX * spr_value->spriteY);
	spr_value->spriteScreenX = (int)((win->screenw / 2)
			* (1 + spr_value->transformX / spr_value->transformY));
	spr_value->vMoveScreen = (int)(0.0 / spr_value->transformY);
	spr_value->spriteHeight = abs((int)(win->screenh
				/ (spr_value->transformY)));
	draw_XY(spr_value, win);
}

void	sprite_print(t_spr_value *spr_value, t_win *win,
		t_tex *spr, double *d_buf)
{
	int	y;
	int	d;

	if (spr_value->transformY > 0 && spr_value->stripe > 0
		&& spr_value->stripe < win->screenw
		&& spr_value->transformY < d_buf[spr_value->stripe])
	{
		y = spr_value->drawStartY;
		while (y < spr_value->drawEndY)
		{
			d = (y - spr_value->vMoveScreen) * 256
				- win->screenh * 128 + spr_value->spriteHeight * 128;
			spr_value->texY = ((d * win->tex_height)
					/ spr_value->spriteHeight) / 256;
			win->spr_color = ((int *)spr->line)
			[win->tex_height * spr_value->texY + spr_value->texX];
			if ((win->spr_color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(win, spr_value->stripe, y, win->spr_color);
			y++;
		}
	}	
}

void	sprites(t_win *win, double *d_buf, t_spr_value *spr_value)
{
	t_tex	*spr;
	int		i;

	spr = &win->texture.spr;
	i = 0;
	while (i < win->sprite_count)
	{
		assign_value(win, i, spr_value);
		spr_value->stripe = spr_value->drawStartX;
		while (spr_value->stripe < spr_value->drawEndX)
		{
			spr_value->texX = (int)(256 * (spr_value->stripe
						- (-spr_value->spriteWidth / 2
							+ spr_value->spriteScreenX))
					* 64 / spr_value->spriteWidth) / 256;
			sprite_print(spr_value, win, spr, d_buf);
			spr_value->stripe++;
		}
		i++;
	}
}

int	spr1(t_win *win, double *d_buf)
{
	t_spr_value	*spr_value;

	spr_value = (t_spr_value *)malloc(sizeof(t_spr_value));
	if (!(spr_value))
		return (-1);
	sort_sprites(win->sprites, win->sprite_count);
	calc_sprite_distance(win);
	sprites(win, d_buf, spr_value);
	free (spr_value);
	return (0);
}
