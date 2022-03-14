NAME	:= so_long
SRC		:=  ./src/mandatory/get_next_line_utils.c	./src/mandatory/get_next_line.c	./src/mandatory/Hooks.c	./src/mandatory/Init.c	./src/mandatory/main.c	./src/mandatory/Movement.c	./src/mandatory/Render.c	./src/mandatory/ValidateMapObjects.c	./src/mandatory/ValidateMapStructure.c	./src/mandatory/Errors2.c	./src/mandatory/Errors1.c
SRCB	:=  ./src/bonus/Loops_bonus.c ./src/bonus/get_next_line_utils_bonus.c	./src/bonus/get_next_line_bonus.c	./src/bonus/Hooks_bonus.c	./src/bonus/Init_bonus.c	./src/bonus/main_bonus.c	./src/bonus/Movement_bonus.c	./src/bonus/Render_bonus.c	./src/bonus/ValidateMapObjects_bonus.c	./src/bonus/ValidateMapStructure_bonus.c	./src/bonus/Errors2_bonus.c	./src/bonus/Errors1_bonus.c
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