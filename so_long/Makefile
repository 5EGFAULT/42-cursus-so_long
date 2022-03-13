NAME	:= so_long
SRC		:=  ./src/SrcMandatory/get_next_line_utils.c	\
			./src/SrcMandatory/get_next_line.c			\
			./src/SrcMandatory/Hooks.c					\
			./src/SrcMandatory/Init.c					\
			./src/SrcMandatory/main.c					\
			./src/SrcMandatory/Movement.c				\
			./src/SrcMandatory/Render.c					\
			./src/SrcMandatory/ValidateMapObjects.c		\
			./src/SrcMandatory/ValidateMapStructure.c	\
			./src/SrcMandatory/Errors2.c				\
			./src/SrcMndatory/Errors1.c
SRCB	:=  Loops_bonus.c			\
			main_bonus.c			
OBJ		:= $(patsubst %.c, %.o, $(SRC)) 
OBJB	:= $(patsubst %.c, %.o, $(SRCB)) 
CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror
LIBFT	:= ./src/libft/libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(LIBFT) $(OBJ) -o $(NAME) $(LIBFT)
%.o: %.c
	$(CC) $(FLAGS) -c $<  -o $@
$(LIBFT):
	make -C ./src/libft
clean:
	rm -f $(OBJ) $(OBJB)
	make -C ./src/libft fclean
fclean: clean
	rm -f $(NAME)
re: fclean all
bonus: $(LIBFT) $(OBJB)
	$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(LIBFT) $(OBJB) -o $(NAME) $(LIBFT)