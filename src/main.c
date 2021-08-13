#include "wolf.h"

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
	{
		return (0);
	}
	if (write_to_image(win, ar) == -1)
	{
		printf("%s\n", "there is no texture like that");
		return (0);
	}
	return (0);
}
