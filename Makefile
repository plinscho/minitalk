# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 19:22:38 by plinscho          #+#    #+#              #
#    Updated: 2023/10/05 18:57:25 by plinscho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
#SERVER_BONUS = server_bonus
#CLIENT_BONUS = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS_SERVER = server.c
OBJ_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = client.c
OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)

#SRCS_SERVER_BONUS = server_bonus.c
#OBJ_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

#SRCS_CLIENT_BONUS = client_bonus.c
#OBJ_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_PATH)
	
$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@ -L$(LIBFT_PATH) $(LIBFT)

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@ -L$(LIBFT_PATH) $(LIBFT)

$(OBJ_SERVER): $(SRCS_SERVER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CLIENT): $(SRCS_CLIENT) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -s -C $(LIBFT_PATH)
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	@printf "Removed Objects\n"

fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT_PATH)
	@$(RM) $(SERVER) $(CLIENT) 
	@echo "Executables Removed\n"

re: fclean all

.PHONY: all clean fclean re bonus