# -------------------------
# CONFIG
# -------------------------
NAME    = push_swap
CC      = cc
CFLAGS  = -Wall
LIBFT   = libft/libft.a
PRINTF  = libft/ft_printf/ft_printf.c libft/ft_printf/ft_utils.c

# Pastas
SRC_DIR = .
OBJ_DIR = obj

# Ficheiros fonte
SRC     = pushswap.c list_utils.c utils.c helpers.c

# Gerar os .o na pasta obj/
OBJ     = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# -------------------------
# Regras principais
# -------------------------
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compilar .c -> .o na pasta obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar pasta obj se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# -------------------------
# Limpezas
# -------------------------
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

