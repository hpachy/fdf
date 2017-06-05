# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpachy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/05 15:32:15 by hpachy            #+#    #+#              #
#    Updated: 2017/04/05 15:32:16 by hpachy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCDIR			= srcs/
INCDIR			= includes/

SRC 			= 	ft_putchar.c \
					ft_strcat.c \
					ft_strcmp.c \
					ft_strcpy.c \
					ft_strdup.c \
					ft_strlen.c \
					ft_strncpy.c \
					ft_strncat.c \
					ft_atoi.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strstr.c \
					ft_strnstr.c \
					ft_strnstr.c \
					ft_strncmp.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memchr.c \
					ft_memccpy.c \
					ft_putnbr.c \
					ft_putnbr_fd.c \
					ft_putchar_fd.c \
					ft_putstr.c \
					ft_putstr_fd.c \
					ft_putendl.c \
					ft_putendl_fd.c \
					ft_memalloc.c \
					ft_memdel.c \
					ft_strnew.c \
					ft_strdel.c \
					ft_strclr.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strequ.c \
					ft_strnequ.c \
					ft_strsub.c \
					ft_strjoin.c \
					ft_memcmp.c \
					ft_strtrim.c \
					ft_strsplit.c \
					ft_itoa.c \
					ft_itoa.c \
					ft_memmove.c \
					ft_strlcat.c \
					ft_lstdelone.c \
					ft_lstnew.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_intlen.c \
					ft_isspace.c \
					ft_add_end.c \
					get_next_line.c \
					ft_itoa_base.c \
					ft_c_strnew.c \
					ft_itoa_intmax_t.c \
					ft_itoa_long_long.c \
					ft_itoa_long.c \
					ft_itoa_size.c \
					ft_itoa_short.c \
					ft_itoa_signed_char.c \
					ft_itoa_ulong_long.c \
					ft_itoa_ulong.c \
					ft_itoa_base_size.c \
					ft_itoa_base_short.c \
					ft_itoa_base_uchar.c \
					ft_uintlen.c \

OBJ				= $(SRC:.c=.o)
CFLAGS			= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33;32mCompilation de la libairie $(NAME)\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[33;32m===> OK <===\033[0m"

%.o: $(SRCDIR)%.c 
	@echo "\033[33;32mCompilation .c > .o\033[0m"
	@gcc $(CFLAGS) -o $@ -c $< -I$(INCDIR)

clean:
	@echo "\033[31mremove libft/*.o\033[0m"
	@rm -f $(OBJ)
	@echo "\033[33;32m===> OK <===\033[0m"

fclean: clean
	@echo "\033[31mremove libft.a $(NAME)\033[0m"
	@rm -f $(NAME)
	@echo "\033[33;32m===> OK <===\033[0m"

re: fclean all