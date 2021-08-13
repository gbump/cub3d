#include "../wolf.h"

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->line + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	create_image(t_win *win)
{
	win->image = mlx_new_image(win->mlx, win->screenw, win->screenh);
	win->line = mlx_get_data_addr(win->image, &win->bpp,
			&win->line_l, &win->en);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = tmp->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	lst = NULL;
}
