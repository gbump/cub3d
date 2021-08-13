#ifndef WOLF_H
# define WOLF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "../minilibx_opengnl/mlx.h"
# include "gnl/get_next_line.h"

# define MOVE_FORWARD 13
# define MOVESPEED 0.1
# define MOVE_BACK 1
# define MOVE_RIGHT 2
# define MOVE_LEFT 0
# define TURN_RIGHT 124
# define TURN_LEFT 123
# define ESC 53

typedef struct s_sprite
{
	double			x;
	double			y;
	double			relX;
	double			relY;
	double			distance;
}				t_sprite;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	char			**map;
}				t_list;

typedef struct s_tex
{
	void			*img;
	char			*line;
	int				width;
	int				height;
	int				bpp;
	int				line_l;
	int				en;
}				t_tex;

typedef struct s_texture
{
	t_tex		north;
	t_tex		south;
	t_tex		west;
	t_tex		east;
	t_tex		spr;
}				t_texture;

typedef struct s_spr_value
{
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		vMoveScreen;
	int		spriteHeight;
	int		drawStartY;
	int		drawStartX;
	int		drawEndY;
	int		drawEndX;
	int		spriteWidth;
	int		texY;
	int		texX;
	int		stripe;
}				t_spr_value;

typedef struct s_img
{
	int			width;
	int			height;
	char		*buffer;
	void		*img_ptr;
}				t_img;

typedef struct s_win
{
	void		*mlx;
	void		*mlx_ptr;
	void		*win;
	void		*image;
	int			meet_one;
	void		*image_data;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	int			color;
	int			spr_color;
	char		*line;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	int			move_right;
	int			move_left;
	int			move_back;
	int			move_forth;
	int			turn_right;
	int			turn_left;
	int			key_touch;
	double		planeX;
	double		planeY;
	char		**map;
	int			width;
	int			height;
	double		rotate;
	double		cameraX;
	double		rayPosX;
	double		rayPosY;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			hit;
	int			side;
	double		sideDistX;
	double		sideDistY;
	int			stepX;
	int			stepY;
	double		wall_x;
	int			lineHeight;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			drawStart;
	int			drawEnd;
	int			drawStep;
	t_texture	texture;
	int			screenw;
	int			screenh;
	int			a;
	int			b;
	double		params_count;
	int			extra;
	int			prew;
	int			aftw;
	int			counth;
	int			floor_col;
	int			ceil_col;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sprite;
	int			sprite_count;
	t_sprite	**sprites;
	double		transX;
	double		transY;
	int			sprite_screen;
	int			sprite_width;
	int			sprite_height;
	int			draw_sY;
	int			draw_sX;
	int			draw_eY;
	int			draw_eX;
	int			fst_count;
	int			f;
	int			s;
	int			t;
	char		texx[255];
	int			NSWE_counter;
	int			tex_width;
	int			tex_height;
	int			max_screenw;
	int			max_screenh;
	int			fst_count1;
	int			cl;
	int			fl;
}				t_win;

int		main(int argc, char **argv);
int		scnd_arg_check(int ar, char **argv);
int		frst_arg_check(t_win *win, int ar, char **argv);
int		gnl_map(t_win *win, char **argv);
int		file_validation_check(t_win *win);
int		screenshot(t_win *win);
int		make_map(t_list **head, int size, t_win *win);
int		map_checker(t_win *win);
void	player_params(t_win *win);
int		player_NS(t_win *win, int i, int j);
int		player_WE(t_win *win, int i, int j);
int		dop_circs_prt1(t_win *win, int i, int j);
int		dop_circs_prt2(t_win *win, int i, int j);
int		check_map(t_win *win);
void	map_middle(t_win *win);
int		map_start(t_win *win);
int		map_ending(t_win *win, int i, int j);
int		string_parsing(t_win *win, int i, int j);
int		whats_map(t_win *win, int c);
int		whats_map_S(t_win *win, int c);
int		whats_map_CF(t_win *win, int c);
int		whats_map_R(t_win *win);
int		whats_mapNO(t_win *win, int c, int d);
int		check_CF(t_win *win, int type);
void	CF_color_adder(t_win *win, int type);
int		CF_adder(t_win *win);
int		CF_frst_part(t_win *win);
int		CF_plus(t_win *win);
int		check_params_EA_S(t_win *win);
int		check_params_SO_WE(t_win *win);
int		check_params_F_NO(t_win *win);
int		check_params_R_C(t_win *win);
void	NO_add_texture_prt2(int t1, int t2, t_win *win);
void	NO_add_texture_prt1(int t1, int t2, t_win *win);
int		NO_malloc_prt2(int t1, int t2, int i, t_win *win);
int		NO_malloc_prt1(int t1, int t2, int i, t_win *win);
int		check_NO(t_win *win, int t1, int t2);
int		NO_adder(t_win *win);
int		check_params(t_win *win);
int		CP_sum(t_win *win, int count_param);
int		sum_check_params(t_win *win);
int		check_R(t_win *win);
void	R_adder(t_win *win);
void	R_plus(t_win *win);
int		parse_sprites(t_win *win, int i);
void	sort_sprites(t_sprite **sprites, int num);
void	calc_sprite_distance(t_win *win);
int		spr1(t_win *win, double *d_buf);
void	sprites(t_win *win, double *d_buf, t_spr_value *spr_value);
void	sprite_print(t_spr_value *spr_value, t_win *win,
			t_tex *spr, double *d_buf);
void	assign_value(t_win *win, int i, t_spr_value *spr_value);
void	draw_XY(t_spr_value *spr_value, t_win *win);
int		background(t_win *win);
int		go_up(int key, t_win *win);
int		go_down(int key, t_win *win);
void	check_press(t_win *win);
void	inizialization(t_win *win, int x);
void	add_params(t_win *win);
void	Side(t_win *win);
void	Hit(t_win *win);
void	RayDir(t_win *win);
int		write_to_image(t_win *win, int save);
int		adder(t_win *win);
int		draw(t_win *win);
void	combination(t_win *win, double *d_buf, t_tex *tex);
int		textute_mistakes_prt1(t_win *win);
void	texture_print(t_win *win, int x, t_tex *tex);
int		texture_sprite(t_win *win);
int		texture_west(t_win *win);
int		texture_east(t_win *win);
int		texture_south(t_win *win);
int		texture_north(t_win *win);
void	error_print(int i, t_win *win);
int		all_free(t_win *win);
void	exit_mistakes(t_win *win);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	move_right(t_win *win);
void	move_left(t_win *win);
void	move_back(t_win *win);
void	move_forth(t_win *win);
void	turn_right(t_win *win);
void	turn_left(t_win *win);
int		skipper(t_win *win);
int		search_signs(int i, int j, t_win *win);
int		ft_isdigit(int c);
int		is_whitespace(int c);
void	*ft_calloc(size_t number, size_t size);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
void	create_image(t_win *win);
int		ft_lstsize(t_list *lst);
int		screenshot(t_win *win);

#endif
