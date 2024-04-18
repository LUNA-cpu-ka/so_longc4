SRC = validation.c error.c mlx.c\
	./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
GFLAGS = -Wall -Wextra -Werror 
NAME = so_long.a
LIBFT = libft.a

all: $(NAME)

%.o: %.c
	@cc $(GFLAGS) -c $< -o $@
	@cc -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME)	: $(OBJ) $(LIBFT)
	@echo "making $(NAME)"
	@cc $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	@echo "making libft.."
	@make -C libft
	@mv libft/libft.a .

clean:
	@echo "cleaning.."
	@rm -f $(OBJ) 
	@make -C libft clean
	@rm -fr $(LIBFT)

fclean: clean
	@echo "full cleaning.. "
	@rm -f $(NAME)

re: clean  
	@rm -f $(OBJ)

.SILENT: re clean fclean