NAME :=  so_long
SRC := srcs/main.c srcs/Get_next_line/get_next_line_bonus.c srcs/Get_next_line/get_next_line_utils_bonus.c 
OBJ := srcs/main.o srcs/Get_next_line/get_next_line_bonus.o srcs/Get_next_line/get_next_line_utils_bonus.o 
MAP := maps/map1.ber
LIBFT = srcs/libft/libft.a
CC:= gcc
all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx  -c $<  -o $@ 

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)
	./$(NAME) $(MAP)
$(LIBFT):
		@make -C srcs/libft
		@make -C srcs/libft clean
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
	@make -C srcs/libft fclean
re: fclean all
