# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 16:24:26 by joseferr          #+#    #+#              #
#    Updated: 2023/11/24 16:24:26 by joseferr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = .c

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS)
	ar rc $(NAME) $(SRCS)

clean:
	$(RM) $(SRCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
