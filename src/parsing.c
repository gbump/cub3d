#include <math.h>
#include <stdlib.h>
#include "wolf.h"

int	player_WE(t_win *win, int i, int j)
{
	if (win->map[i][j] == 'W')
	{
		win->dirY = 0.0;
		win->dirX = -1.0;
		win->planeY = 0.66;
		win->planeX = 0.0;
		return (j);
	}
	else if (win->map[i][j] == 'E')
	{
		win->dirY = 0.0;
		win->dirX = 1.0;
		win->planeY = -0.66;
		win->planeX = 0.0;
		return (j);
	}
	return (-2);
}

int	player_NS(t_win *win, int i, int j)
{
	while (win->map[i][j])
	{
		if (win->map[i][j] == 'N')
		{
			win->dirY = -1.0;
			win->dirX = 0.0;
			win->planeY = 0.0;
			win->planeX = -0.66;
			return (j);
		}
		else if (win->map[i][j] == 'S')
		{
			win->dirY = 1.0;
			win->dirX = 0.0;
			win->planeY = 0.0;
			win->planeX = 0.66;
			return (j);
		}
		if (player_WE(win, i, j) != -2)
			return (j);
		j++;
	}
	return (-2);
}

void	player_params(t_win *win)
{
	int	i;
	int	j;

	i = win->a;
	j = win->b;
	while (win->map[i])
	{
		j = 0;
		if (player_NS(win, i, j) != -2)
		{
			j = player_NS(win, i, j);
			break ;
		}
		if (win->map[i][j] == 'N' || win->map[i][j] == 'S'
				|| win->map[i][j] == 'W' || win->map[i][j] == 'E')
			break ;
		i++;
	}
	win->map[i][j] = '0';
	win->posX = (double)(i) + 0.5;
	win->posY = (double)(j) + 0.5;
}

int	map_checker(t_win *win)
{
	int	i;
	int	j;

	if (check_map(win) == -1)
		return (-1);
	player_params(win);
	i = win->a;
	j = 0;
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == '2')
				win->sprite_count++;
			j++;
		}
		i++;
	}
	if ((parse_sprites(win, win->a)) == -1)
	{
		error_print(18, win);
		return (-1);
	}
	return (0);
}

int	make_map(t_list **head, int size, t_win *win)
{
	int		i;
	t_list	*tmp;

	win->map = ft_calloc(size + 1, sizeof(char *));
	if (!win->map)
		return (-1);
	i = -1;
	tmp = *head;
	while (tmp)
	{
		win->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (0);
}

/*int	scnd_arg_check(int ar, char **argv)
{
	int	i;

	i = 0;
	while (ar == 3 && argv[2][i])
		i++;
	if (ar == 3 && i != 6)
		return (-1);
	if (ar == 3 && (argv[2][0] != '-' || argv[2][1] != '-'
				|| argv[2][2] != 's' || argv[2][3] != 'a'
				|| argv[2][4] != 'v' || argv[2][5] != 'e'))
		return (-1);
	return (0);
}

int	frst_arg_check(t_win *win, int ar, char **argv)
{
	int	i;

	i = 0;
	if (ar != 2 && ar != 3)
	{
		error_print(1, win);
		return (-1);
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u'
			|| argv[1][i - 3] != 'c' || argv[1][i - 4] != '.')
	{
		error_print(2, win);
		return (-1);
	}
	if (scnd_arg_check(ar, argv) == -1)
	{
		error_print(4, win);
		return (-1);
	}
	return (0);
}

int	gnl_map(t_win *win, char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;
	int		c;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		error_print(3, win);
		return (-1);
	}
	c = 1;
	while (c)
	{
		if (c == -1)
		{
			error_print(3, win);
			return (-1);
		}
		c = get_next_line(fd, &line);
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	if (make_map(&head, ft_lstsize(head), win) == -1)
	{
		error_print(3, win);
		return (-1);
	}
	return (0);
}

int	file_validation_check(t_win *win)
{
	if (check_params(win) == -1)
	{
		free(win->no);
		free(win->so);
		free(win->ea);
		free(win->we);
		free(win->sprite);
		free(win);
		free(win->map);
		return (-1);
	}
	if (map_checker(win) == -1)
	{
		exit_mistakes(win);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		ar;
	t_win	*win;

	argc = 0;
	win = (t_win *)malloc(sizeof(t_win));
	ar = 0;
	if (!win)
		return (0);
	while (argv[ar])
		ar++;
	if (frst_arg_check(win, ar, argv) == -1)
		return (0);
	if (gnl_map(win, argv) == -1)
		return (0);
	if (file_validation_check(win) == -1)
		return (0);
	if (write_to_image(win, ar) == -1)
	{
		printf("%s\n", "there is no texture like that");
		return (0);
	}
	return (0);
}*/
