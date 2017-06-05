# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpachy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 13:34:13 by hpachy            #+#    #+#              #
#    Updated: 2017/06/03 11:41:25 by hpachy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB = libft/

HEAD = libft/
HEAD2 = Include/
FLAGS = -Wall -Wextra -g
SRC = Src/main.c Src/key_hook.c Src/line.c Src/parsing.c Src/paser2.c Src/pixel.c
OBJ =  main.o key_hook.o line.o parsing.o paser2.o pixel.o

LIBX = -lmlx -lft -framework OpenGL -framework appKit

all: libft $(NAME)

.PHONY : libft clean fclean re

libft :
	@make -C libft

$(NAME) :
	@echo "\033[33;32mCompilation executable : $(NAME)"
	@gcc $(FLAG) -c $(SRC) -I $(HEAD) -I $(HEAD2)
	@echo "\033[33;32mCompilation .o"
	@gcc -o $(NAME)  -L $(LIB) $(OBJ) $(LIBX)
	@echo "\033[33;32m===> OK <==="

clean :
	@echo "\033[31mremove fdf/*.o"
	@rm -f $(OBJ)
	@echo "\033[33;32m===> OK <==="

fclean :	clean
	@echo "\033[31mremove executable : $(NAME)"
	@rm -f $(NAME)
	@echo "\033[33;32m===> OK <==="

re :	fclean all
