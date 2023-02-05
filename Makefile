# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:15:08 by chajjar           #+#    #+#              #
#    Updated: 2023/02/05 21:41:06 by chajjar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC =	srcs/main.c srcs/check_map.c \
		srcs/parsing_map.c srcs/parsing_text_color.c \
		srcs/check_color.c srcs/find_char_map.c \
		srcs/error_msg.c srcs/check_zero.c \
		srcs/check_map_charac.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

all: $(NAME)

dependency:
	make -sC Libft
	make -sC MLX42

.c.o:
	gcc $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): dependency $(OBJ)
	gcc $(DANGER) -o $(NAME) $(OBJ) -LLibft -lft -LMLX42 -lmlx42
	
clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -sC Libft

re: fclean all

test: all
	@./$(NAME)
	@make fclean

# PROTECTION #

.PHONY: all dependency clean fclean aclean re