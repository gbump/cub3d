#include "wolf.h"

static int	list_to_arr(t_list **begin, int size, t_win *win)
{
	int		count;
	t_list	*tmp;

	count = 0;
	win->map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!(win->map))
	{
		ft_lstclear(begin, free);
		error_print(21, win);
		return (-1);
	}
	tmp = *begin;
	while (tmp)
	{
		win->map[count++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	win->map[count] = NULL;
	return (0);
}

int	open_gnl(char **argv, t_win *win)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		close(fd);
		error_print(3, win);
		return (-1);
	}
	return (fd);
}

int	gnl_make(t_list *head, t_win *win)
{
	if (make_map(&head, ft_lstsize(head), win) == -1)
	{
		error_print(3, win);
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
	fd = open_gnl(argv, win);
	if (!fd)
		return (-1);
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
	if (list_to_arr(&head, ft_lstsize(head), win) == -1)
		return (-1);
	ft_lstclear(&head, free);
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
