NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
LIBFT_DIR = libft
LIBFT   = $(LIBFT_DIR)/libft.a

# Pastas
SRC_DIR = .
OBJ_DIR = obj

# Ficheiros fonte
SRC     = main.c helpers.c input_utils.c list_utils.c operations.c prints.c prints2.c sorting_small.c sorting_big.c

# Gerar os .o na pasta obj/
OBJ     = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# -------------------------
# Regras principais
# -------------------------
all: $(LIBFT) $(NAME)

# compilar o executável
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "✅ $(NAME) compilado com sucesso!"

# compilar libft automaticamente
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# compilar .c -> .o na pasta obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# criar pasta obj se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# -------------------------
# Limpezas
# -------------------------
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "🧹 Objetos removidos."

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "🗑️  Tudo limpo."

re: fclean all

.PHONY: all clean fclean re
