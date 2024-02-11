SRC = 	fractol.c hooks.c mandelbrot.c
SRC_BONUS = 
OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:_bonus.c=_bonus.o}
CFLAGS = -Wall -Wextra -Werror -Imlx
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -O3
CC = cc
RM = rm -f
NAME = fractol
NAME_BONUS = checker
LIBFT_DIR = libs/libft
PRINTF_DIR = libs/printf
GNL_DIR = libs/get_next_line
LIBFT_LIB = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/get_next_line.c
GNL_UTLS = $(GNL_DIR)/get_next_line_utils.c
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

%_bonus.o: %_bonus.c checker_bonus.h
	@$(CC) $(CFLAGS) -c -o $@ $<

${NAME}: ${OBJS} $(LIBFT_LIB) $(PRINTF_LIB)
		@echo "Linking with Libft and Ftprintf..."
		@$(CC) $(MLXFLAGS) -o $@ $^
		@echo "Finished"

${NAME_BONUS}: ${OBJS_BONUS} ${GNL} ${GNL_UTLS} $(LIBFT_LIB) $(PRINTF_LIB)
		@echo "Compiling Bonus..."
		@$(CC) $(CFLAGS) -o $@ $^
		@echo "Finished"

$(LIBFT_LIB):
	@echo "Building Libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "Done"

$(PRINTF_LIB):
	@echo "Building Ftprintf..."
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "Done"

all: ${NAME}

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

bonus: ${NAME_BONUS}

.PHONY: clean