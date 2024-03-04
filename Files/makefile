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

# Compiling Variables #
CC		 = cc
CFLAGS	 = -g -Wall -Wextra -Werror

#Names#
NAME	= push_swap

#LIBFT Variables#
LIBFT		= ./libft/libft.a

#Sources#
SRCS = ./main.c ./push.c ./rev_rotate.c ./rotate.c ./sortiny.c ./stack.c ./swap.c ./janitor.c ./bigsort.c ./stack_utils.c ./sort_utils.c ./sort_utils2.c

OBJS = $(SRCS:.c=.o)

##################### MAKEFILE RULES ##########################

all: $(LIBFT) $(NAME)

libft: $(LIBFT)

clean:
	${MAKE} clean -C ./libft
	rm -rf $(OBJS)
	
fclean: clean
	${MAKE} fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

################# MAKING MAIN PROGRAM ##################################

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft 

################################ MAKING BONUS PROGRAMS #################
#
#$(SERVER_BONUS): $(OBJS_BNS_SR)
#	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJS_BNS_SR) L./libft -lft 
#
################################# Making LIBFT #########################
$(LIBFT):
	${MAKE} --no-print-directory -C ./libft