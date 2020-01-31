# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 12:40:12 by jgroleo           #+#    #+#              #
#    Updated: 2020/01/30 12:44:42 by jgroleo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIB 		= libft/libft.a

HEADER_NAME		= push_swap.h
NAME_CHECK 		= checker

INC_DIR 		= ./includes/
INC_LIB_FT 		= ./libft/includes/
SRC_DIR 		= ./src/
OBJ_DIR 		= ./obj/

SRC_NAME_CHECK	= checker.c

HEADER 			= $(addprefix $(INC_DIR), $(HEADER_NAME))

SRC_CHECK		= $(addprefix $(SRC_PATH), $(SRC_NAME_CHECK))
OBJ_CHECK		= $(addprefix $(OBJ_DIR), $(SRC_NAME_CHECK:.c=.o))

CC				= gcc
FLAGS			= -Wall -Wextra -Werror
GCC_LIBFT 		= -L ./libft -l ft

all: $(NAME_CHECK)

$(NAME_CHECK): $(OBJ_DIR) $(OBJ_CHECK) $(NAME_LIB) $(HEADER)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_CHECK) $(FLAGS) -o $(NAME_CHECK)

$(OBJ_DIR):
	@mkdir -p obj

$(NAME_LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INC_DIR) -I $(INC_LIB_FT) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME_PS) $(NAME_CHECK)
	@make fclean -C libft/

re: fclean all
