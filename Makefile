NAME = fdf

SRC =	fdf.c \
		take_file.c \
		draw.c \
		key.c \
		math.c \
		some_functions.c


LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

MLX_F =  -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/ re
	@make -C ./libft/ clean
	@clang $(FLAGS) $(MLX_F) $(LIB) $(OBJ) -o $(NAME)
	@echo "Compilation done!"

%.o: %.c
	@clang -c $(FLAGS) -o $@ $<

lldb:
	@clang -g $(FLAGS) $(MLX_F) $(LIB) $(SRC) -o debug
	@echo "Use 'debug' for lldb."

lclean:
	@rm -f debug
	@echo "'debug' removed!"

clean:
	@rm -f $(OBJ)
	@echo "Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed!"

re: fclean all