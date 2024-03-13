# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 10:49:53 by joseferr          #+#    #+#              #
#    Updated: 2024/02/26 10:49:53 by joseferr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Names
NAME	= checker

# Push_Swap Bonus Sources
SRCS = 	./checker.c \
		./checker_val.c \
		./get_next_line.c \
		./checker_utils.c \
		./get_next_line_utils.c \
		./Bmoves/push.c \
		./Bmoves/swap.c \
		./Bmoves/rotate.c \
		./Bmoves/reverse_rotate.c \



OBJS = $(SRCS:.c=.o)

# Compiler
CC		 = gcc
RM 		=	rm -f
CFLAGS	 = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
