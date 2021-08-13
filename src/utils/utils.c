#include "../wolf.h"

/*void	error_print_prt3(int i)
{
	if (i == 13)
		printf("%s\n", "smth wrong with sprites");
	if (i == 14)
		printf("%s\n", "smth wrong in param part");
	if (i == 15)
		printf("%s\n", "not a valid map");
	if (i == 16)
		printf("%s\n", "map has /n in it");
	if (i == 17)
		printf("%s\n", "map has no or few players");
	if (i == 18)
		printf("%s\n", "problemas with sprite parsing");
	if (i == 19)
		printf("%s\n", "memory probems with d_buf");
	if (i == 20)
		printf("%s\n", "cannot open the bmp the map file");
}

void	error_print_prt2(int i)
{
	if (i == 6)
		printf("%s\n", "problems with resolution");
	if (i == 7)
		printf("%s\n", "problems with ceiling color");
	if (i == 8)
		printf("%s\n", "problems with floor color");
	if (i == 9)
		printf("%s\n", "problems with north texture");
	if (i == 10)
		printf("%s\n", "problems with south texture");
	if (i == 11)
		printf("%s\n", "problems with west texture");
	if (i == 12)
		printf("%s\n", "problems with east texture");
	if (i > 12)
		error_print_prt3(i);
}

void	error_print(int i, t_win *win)
{
	printf("%s\n", "Error");
	if (i == 1 || i == 2 || i == 3 || i == 4)
		free (win);
	if (i == 1)
		printf("%s\n", "wrong number of arguments in command");
	if (i == 2)
		printf("%s\n", "the format of the frst argument isnt correct");
	if (i == 3)
		printf("%s\n", "cannot normally read the map file");
	if (i == 4)
		printf("%s\n", "the format of the second argument isnt correct");
	if (i == 5)
		printf("%s\n", "the wrong number of params");
	if (i > 5)
		error_print_prt2(i);
}*/

void	*ft_calloc(size_t number, size_t size)
{
	unsigned int	total;
	char			*a;
	unsigned int	i;

	i = 0;
	total = number * size;
	a = malloc(total);
	if (!(a))
		return (NULL);
	while (total--)
	{
		a[i] = 0;
		i++;
	}
	return ((void *)a);
}

/*t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!(new))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}*/

int	is_whitespace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

/*int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	l = ft_lstlast(*lst);
	l->next = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*j;

	i = *lst;
	while (i)
	{
		j = i->next;
		if (del)
			del(i->content);
		free(i);
		i = j;
	}
	*lst = NULL;
}*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	search_signs(int i, int j, t_win *win)
{
	if (win->map[i][j] == 'N' || win->map[i][j] == 'S' || win->map[i][j] == 'W'
	|| win->map[i][j] == 'E' || win->map[i][j] == '1'
	|| win->map[i][j] == '2' || win->map[i][j] == '0')
		return (1);
	return (0);
}

int	skipper(t_win *win)
{
	while (ft_isdigit(win->map[win->a][win->b]) == 0)
	{
		if (win->map[win->a][win->b] == ' ')
			win->b++;
		else
			return (-1);
	}
	return (0);
}
