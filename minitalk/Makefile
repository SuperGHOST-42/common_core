# **************************************************************************** #
#                                MiniTalk Makefile                             #
# **************************************************************************** #

# Compilador
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# Binários
SERVER  := server
CLIENT  := client

# Fontes
SRCS_S  := server.c
SRCS_C  := client.c
OBJS_S  := $(SRCS_S:.c=.o)
OBJS_C  := $(SRCS_C:.c=.o)

# Libft
LIBFT_DIR := libft
LIBFT     := $(LIBFT_DIR)/libft.a

# Targets
.PHONY: all clean fclean re

all: $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_S) $(LIBFT) -o $@

$(CLIENT): $(OBJS_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_C) $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS_S) $(OBJS_C)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
