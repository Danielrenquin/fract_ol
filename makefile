
CC = clang
CFLAGS	=	-Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
AR		=	ar rcs
RM		=	/bin/rm -f

OBJS_DIR = ./objs/
NAME = fractol
SRC_FILES	= main.c data_init.c graphic.c events.c math.c utils.c
C_OBJS = $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))
HEADERS = fractol.h
LIBFT_DIR = ./lib/libft
PRINTF_DIR = ./lib/ftprintf
LIB = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf 

all:$(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) $(MLX_FLAGS) -o $(NAME) $(LIB)

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -sC $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	@$(MAKE) -sC $(PRINTF_DIR)

clean:
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(PRINTF_DIR) fclean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
