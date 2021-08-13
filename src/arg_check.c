#include "wolf.h"

int	scnd_arg_check(int ar, char **argv)
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
