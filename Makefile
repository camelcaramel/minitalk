# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 16:25:05 by donghwik          #+#    #+#              #
#    Updated: 2021/08/25 15:54:48 by donghwik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra

SERVER = server
SERVER_SRCS = server.o utils.o utils2.o

CLIENT = client
CLIENT_SRCS = client.o utils.o utils2.o

all : $(SERVER) $(CLIENT)

$(CLIENT) : $(CLIENT_SRCS)
	$(CC) $(CLIENT_SRCS) -o $(CLIENT)

$(SERVER) : $(SERVER_SRCS)
	$(CC) $(SERVER_SRCS) -o $(SERVER)

%.o : %.c
	$(CC) $(FLAGS) $< -c

clean :
	rm -f $(SERVER_SRCS) $(CLIENT_SRCS)

fclean : clean
	rm -f $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re