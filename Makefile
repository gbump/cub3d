NAME = cub3D

MLX = minilibx_opengnl/libmlx.a

OBJD = objects/
PAR = src/params
MAP = src/map_parser
RAY = src/raycasting
SPR = src/sprites
UT = src/utils
GNL = src/gnl
BMP = screenshot.bmp

SRS = 	src/main.c \
		src/begin.c \
		src/parsing.c \
		src/bmp.c \
		src/arg_check.c \
		src/params/CF_params.c \
		src/params/check_params.c \
		src/params/malloc_tex_NO.c \
		src/params/params.c \
		src/params/resolution.c \
		src/map_parse/whats_map.c \
		src/map_parse/dot_circ.c \
		src/map_parse/map_checker.c \
		src/raycasting/background.c \
		src/raycasting/raycast_utils.c \
		src/raycasting/raycasting.c \
		src/raycasting/tex_error_print.c \
		src/raycasting/texture_put.c \
		src/raycasting/press.c \
		src/sprites/parse_sprites.c \
		src/sprites/sort_dist.c \
		src/sprites/sprites4.0.c \
		src/utils/error_print.c \
		src/utils/free_exit.c \
		src/utils/list_utils.c \
		src/utils/move.c \
		src/utils/turn.c \
		src/utils/utils.c \
		src/utils/utils2_0.c \
		src/gnl/get_next_line_utils.c \
		src/gnl/get_next_line.c \


SRCD = src/
INCLUDES =  src/wolf.h \
			src/gnl/get_next_line.h \

CFLAGS = -g -Wall -Wextra -Werror 

MINILIBFLAGS =  -framework OpenGL -framework Appkit

CC = gcc

OBJSRCS = $(SRS:.c=.o)

$(NAME) : $(OBJSRCS) $(INCLUDES)
	@make -C ./minilibx_opengnl
	@$(CC) $(CFLAGS) $(SRS) $(MINILIBFLAGS) $(MLX) -o $(NAME)
	@rm -rf cub3D.dSYM

all: $(NAME)

clean:
	@make clean -C ./minilibx_opengnl
	@rm -rf $(OBJSRCS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BMP)
	@make fclean -C $(MLX)

re: fclean all