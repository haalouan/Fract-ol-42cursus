SRCS = fractal.c fractal_init.c fractal_moves.c hooks_handler.c  math_utils.c functions_helpers1.c  free_operations.c check_errors.c
BSRCS = fractal_bonus.c fractal_init_bonus.c fractal_moves_bonus.c burning_ship.c hooks_handler_bonus.c hooks_handler_burning_ship.c math_utils.c functions_helpers1.c  free_operations.c check_errors.c
NAME = fractol
BNAME = fractol_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS =  -lmlx -framework OpenGL -framework AppKit
OBJ = ${SRCS:.c=.o} 
BOBJ = ${BSRCS:.c=.o}

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(MLX_FLAGS) -o $@ $^

%.o: %.c fractal.h
	$(CC) $(FLAGS) -c $< -o  $@

bonus:	$(BNAME)

$(BNAME): $(BOBJ)
	$(CC)  $(MLX_FLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(BOBJ)
	
fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: clean