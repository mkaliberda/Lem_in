# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/10 17:54:28 by mkaliber          #+#    #+#              #
#    Updated: 2017/10/10 17:54:44 by mkaliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = -L./libft -lft

FLAGS = -Wall -Wextra -Werror

SRC = check_connection.c check_room.c ft_strjoinf.c logic_to_find.c main.c plushki.c usage.c validate_connect.c usage_print.c go_ant.c

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
		make -C libft/
		gcc $(LIB) -o $(NAME) $(BINS)
%.o: %.c
		gcc -c -o $@ $<
clean:
		make -C libft/ clean
		rm -rf $(BINS)
fclean: clean
		make -C libft/ fclean
		rm -f $(NAME)
re: fclean all
