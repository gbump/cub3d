#include "../wolf.h"

int	texture_north(t_win *win)
{
	t_tex	*north;

	north = &win->texture.north;
	north->img = mlx_xpm_file_to_image(win->mlx, win->no,
			&win->tex_width, &win->tex_height);
	if (!north->img)
		return (-1);
	north->line = mlx_get_data_addr(north->img, &north->bpp,
			&north->line_l, &north->en);
	return (0);
}

int	texture_south(t_win *win)
{
	t_tex	*south;

	south = &win->texture.south;
	south->img = mlx_xpm_file_to_image(win->mlx, win->so,
			&win->tex_width, &win->tex_height);
	if (!south->img)
		return (-1);
	south->line = mlx_get_data_addr(south->img, &south->bpp,
			&south->line_l, &south->en);
	return (0);
}

int	texture_east(t_win *win)
{
	t_tex	*east;

	east = &win->texture.east;
	east->img = mlx_xpm_file_to_image(win->mlx, win->ea,
			&win->tex_width, &win->tex_height);
	if (!east->img)
		return (-1);
	east->line = mlx_get_data_addr(east->img, &east->bpp,
			&east->line_l, &east->en);
	return (0);
}

int	texture_west(t_win *win)
{
	t_tex	*west;

	west = &win->texture.west;
	west->img = mlx_xpm_file_to_image(win->mlx, win->we,
			&win->tex_width, &win->tex_height);
	if (!west->img)
		return (-1);
	west->line = mlx_get_data_addr(west->img, &west->bpp,
			&west->line_l, &west->en);
	return (0);
}

int	texture_sprite(t_win *win)
{
	t_tex	*spr;

	spr = &win->texture.spr;
	spr->img = mlx_xpm_file_to_image(win->mlx, win->sprite,
			&win->tex_width, &win->tex_height);
	if (!spr->img)
		return (-1);
	spr->line = mlx_get_data_addr(spr->img, &spr->bpp, &spr->line_l, &spr->en);
	return (0);
}
