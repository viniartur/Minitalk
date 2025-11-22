# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvieira <vvieira@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 20:09:36 by vvieira           #+#    #+#              #
#    Updated: 2025/11/20 20:09:37 by vvieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET  = \033[0m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
RED    = \033[1;31m

NAME    = minitalk
SERVER  = server
CLIENT  = client
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

LIBFT   = ./libft/libft.a
FTPRINTF = ./ft_printf/libftprintf.a

all: $(LIBFT) $(FTPRINTF) $(SERVER) $(CLIENT)

$(LIBFT):
	@$(MAKE) -s -C ./libft
	@echo "$(GREEN) Libft$(RESET)"
	
$(FTPRINTF):
	@$(MAKE) -s -C ./ft_printf
	@echo "$(GREEN) Ft_printf$(RESET)"
	
$(SERVER): server.c minitalk.h
	@$(CC) $(CFLAGS) -o $(SERVER) server.c $(LIBFT) $(FTPRINTF)
	@echo "$(GREEN) Server$(RESET)"

$(CLIENT): client.c minitalk.h
	@$(CC) $(CFLAGS) -o $(CLIENT) client.c $(LIBFT) $(FTPRINTF)
	@echo "$(GREEN) Client$(RESET)"
	@echo "$(GREEN)Compiled successfully!$(RESET)"    
	
clean:
	@$(RM) $(SERVER) $(CLIENT)
	@$(MAKE) clean -s -C ./libft
	@$(MAKE) clean -s -C ./ft_printf
	@echo "$(RED) Objects$(RESET)"

fclean: clean
	@$(MAKE) fclean -s -C ./libft
	@$(MAKE) fclean -s -C ./ft_printf
	@echo "$(RED) Executables!$(RESET)"
	@echo "$(RED)Removed!$(RESET)"
re: fclean all

.PHONY: all clean fclean re
