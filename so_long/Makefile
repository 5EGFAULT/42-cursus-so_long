NAME	:= so_long
SRC		:=  get_next_line_utils.c	\
			get_next_line.c			\
			Hooks.c					\
			Init.c					\
			main.c					\
			Movement.c				\
			Render.c				\
			ValidateMapObjects.c	\
			ValidateMapStructure	
SRCB	:=  Loops_bonus.c			\
			main_bonus.c			
OBJ		:= $(patsubst %.c, %.o, $(SRC)) 
LIBFT	:= srcs/libft/libft.a
CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror

.PHONY: all clean fclean re 

all: $(NAME)
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)
$(LIBFT):
	@make -C srcs/libft
%.o: %.c
	$(CC) $(FLAGS) -c $<  -o $@
clean:
	@rm -f $(OBJ)
	@make -C srcs/libft fclean
fclean: clean
	@rm -f $(NAME)
re: fclean all
bonus: $(NAME)