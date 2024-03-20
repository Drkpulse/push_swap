# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 10:49:53 by joseferr          #+#    #+#              #
#    Updated: 2024/03/18 13:30:54 by joseferr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#Names
NAME	= push_swap

#LIBFT Variables
LIBFT		= ./libft/libft.a

# Push_Swap Sources
SRCS = 	./main.c \
		./stack.c \
		./janitor.c \
		./sorting.c \
		./sort_utils.c \
		./stack_utils.c \
		./sort_utils2.c \
		./push.c \
		./swap.c \
		./rotate.c \
		./rev_rotate.c

OBJS = $(SRCS:.c=.o)

# Compiler
CC		 = gcc
RM 		=	rm -f
CFLAGS	 = -Wall -Wextra -Werror

# Colours
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

# RULES
all: $(LIBFT) $(NAME)
	@printf "$(PURPLE)==> $(GREEN)🚀 Push_swap compiled \n\n$(RESET)"

libft: $(LIBFT)

clean:
	${MAKE} clean -C ./libft
	$(RM) $(OBJS)
	@printf "\n$(PURPLE)==> $(RED)🧹 Cleaned Temp Push_swap \n$(RESET)"

fclean: clean
	${MAKE} fclean -C ./libft
	$(RM) $(NAME)
	@printf "\n$(PURPLE)==> $(RED)🗑️ Removed Push_swap \n$(RESET)"

re: fclean all
	@printf "$(PURPLE)==> $(PURPLE)🪄 Push_swap recompiled \n$(RESET)"

debug: all clean

	@printf "$(PURPLE)==> $(GREEN)🚀 Push_swap compiled for debug \n\n$(RESET)"

# Full Program
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

# BONUS
#
#$(SERVER_BONUS): $(OBJS_BNS_SR)
#	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJS_BNS_SR) L./libft -lft
#
# LIBFT
$(LIBFT):
	${MAKE} --no-print-directory -C ./libft
