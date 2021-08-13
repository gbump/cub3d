#include "../wolf.h"

void	check_press(t_win *win)
{
	if (win->move_forth)
		move_forth(win);
	if (win->move_back)
		move_back(win);
	if (win->turn_right)
		turn_right(win);
	if (win->turn_left)
		turn_left(win);
	if (win->move_right)
		move_right(win);
	if (win->move_left)
		move_left(win);
}

int	go_up(int key, t_win *win)
{
	if (key == ESC)
		all_free(win);
	 else
	{
		win->key_touch = key;
		check_press(win);
	}
	key = win->key_touch;
	if (key == MOVE_LEFT)
		win->move_left = 0;
	if (key == MOVE_RIGHT)
		win->move_right = 0;
	if (key == MOVE_FORWARD)
		win->move_forth = 0;
	if (key == MOVE_BACK)
		win->move_back = 0;
	if (key == TURN_LEFT)
		win->turn_left = 0;
	if (key == TURN_RIGHT)
		win->turn_right = 0;
	return (0);
}

int	go_down(int key, t_win *win)
{
	if (key == MOVE_LEFT)
		win->move_left = 1;
	if (key == MOVE_RIGHT)
		win->move_right = 1;
	if (key == MOVE_FORWARD)
		win->move_forth = 1;
	if (key == MOVE_BACK)
		win->move_back = 1;
	if (key == TURN_LEFT)
		win->turn_left = 1;
	if (key == TURN_RIGHT)
		win->turn_right = 1;
	return (0);
}
