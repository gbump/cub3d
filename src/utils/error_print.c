#include "../wolf.h"

static void	error_print_prt3(int i)
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
	if (i == 21)
		printf("%s\n", "malloc problems");
}

static void	error_print_prt2(int i)
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
}
