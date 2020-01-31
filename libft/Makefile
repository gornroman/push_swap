# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 16:42:55 by jgroleo           #+#    #+#              #
#    Updated: 2020/01/30 11:33:33 by jgroleo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

INC_PATH = ./includes/
SRC_PATH = ./src/
OBJ_DIR = ./obj/

HEADER_NAME = libft.h get_next_line.h

SRC_NAME = ft_isprint.c ft_memset.c ft_strcat.c ft_striteri.c ft_strnequ.c ft_toupper.c ft_itoa.c \
		   ft_putchar.c ft_strchr.c ft_strjoin.c ft_strnew.c ft_memalloc.c ft_putchar_fd.c \
		   ft_strclr.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_memccpy.c ft_putendl.c ft_strcmp.c \
		   ft_strlen.c ft_strrchr.c ft_bzero.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strmap.c \
		   ft_strsplit.c ft_isalnum.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strmapi.c ft_strstr.c \
		   ft_isalpha.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strncat.c ft_strsub.c \
		   ft_isascii.c ft_memdel.c ft_putstr.c ft_strequ.c ft_strncmp.c ft_strtrim.c \
		   ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_striter.c ft_strncpy.c ft_tolower.c \
		   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		   ft_str_is_alpha.c ft_str_is_lowercase.c ft_str_is_uppercase.c ft_str_is_numeric.c \
		   ft_str_is_printable.c ft_strndup.c get_next_line.c

OBJ_NAME = $(SRC_NAME:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
HEADER = $(addprefix $(INC_PATH), $(HEADER_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_PATH)%.c $(HEADER)
	@gcc -c -I $(INC_PATH) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
