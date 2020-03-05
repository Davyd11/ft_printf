# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 15:18:42 by davyd11           #+#    #+#              #
#    Updated: 2020/03/05 17:51:22 by dpuente-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_PATH = ./
LIB_PATH = libft
INC_PATH = ./
OBJ_PATH = ./obj
OBJLIB_PATH = ./objs


SRC_NAME =	ft_printf.c \
			ft_print_int.c \
			ft_print_char.c \
			flag_short.c \
			not_show.c \
			ft_int_hex.c \
			print_utils.c \
			


LIB_NAME = 	ft_strlen.c \
			ft_putstr_fd.c \
			ft_bzero.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_strchr.c \
			ft_atoi.c \
			ft_nbrlen.c \
			ft_nbr_hex_len.c\
			


INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB) $(INC_NAME)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir -p $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

compile:
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) Main.c

clean:
	@rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	@rm -rf ./obj $(NAME)
	@rm -rf $(OBJ_PATH)
	@rm -rf *.out
	@rm -rf $(OBJLIB_PATH)
	
re: fclean all

.PHONY: fclean clean re