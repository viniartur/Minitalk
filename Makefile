
# Nomes dos executáveis
CLIENT = client
SERVER = server

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

# Arquivos fonte
CLIENT_SRC = client.c
SERVER_SRC = server.c
UTILS_SRC = utils.c

# Arquivos objeto
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

# Regra principal
all: $(SERVER) $(CLIENT)

# Compilar servidor
$(SERVER): $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(SERVER)

# Compilar cliente
$(CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(CLIENT)

# Compilar objetos
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpar objetos
clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(UTILS_OBJ)

# Limpar tudo
fclean: clean
	rm -f $(CLIENT) $(SERVER)

# Recompilar
re: fclean all

.PHONY: all clean fclean re