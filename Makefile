SRC = 	mandatory/fractol.c mandatory/hooks.c mandatory/mandelbrot.c \
		mandatory/julia.c mandatory/operations.c mandatory/render.c
SRC_BONUS = bonus/fractol_bonus.c bonus/hooks_bonus.c bonus/mandelbrot_bonus.c \
			bonus/julia_bonus.c bonus/operations_bonus.c bonus/render_bonus.c \
			bonus/bs_utils_bonus.c bonus/ship_bonus.c
OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:_bonus.c=_bonus.o}
CFLAGS = -Wall -Wextra -Werror -Imlx
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -O3
CC = cc
RM = rm -f
NAME = fractol
NAME_BONUS = fractol_bonus
LIBFT_DIR = libs/libft
PRINTF_DIR = libs/printf
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a


bonus/%_bonus.o: bonus/%_bonus.c bonus/fractol_bonus.h
	@$(CC) $(CFLAGS) -c -o $@ $<

all: pre ${NAME}

mandatory/%.o: mandatory/%.c mandatory/fractol.h
	@$(CC) $(CFLAGS) -c -o $@ $<

${NAME}: ${OBJS} ${LIBFT_LIB} ${PRINTF_LIB}
		@echo "Linking with Libft and Ftprintf..."
		@$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^
		@echo "Finished"

${NAME_BONUS}: ${OBJS_BONUS} $(LIBFT_LIB) $(PRINTF_LIB)
		@echo "Compiling Bonus..."
		@$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^
		@echo "Finished"

pre:
	@echo "Compiling..."
	@echo "Building Libft..."
	@cd $(LIBFT_DIR) && make
	@echo "Building Ftprintf..."
	@cd $(PRINTF_DIR) && make
	@echo "Done"

clean:
	@echo "Cleaning..."
	@${RM} $(OBJS) ${OBJS_BONUS}
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "Finished"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@${RM} ${NAME} ${NAME_BONUS}

re: fclean all

bonus: pre ${NAME_BONUS}

.PHONY: clean