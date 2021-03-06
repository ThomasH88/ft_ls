# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2018/10/23 14:43:09 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

HEADER = ft_ls.h

LIB1 = libft/libft.a

LIB2 = libft/b_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra -o

SRCS = ft_ls.c \
	   basic_list.c \
	   classify.c \
	   exit_errors.c \
	   print_list.c \
	   print_long_fmt.c \
	   side_long_fmt.c \
	   side_funct.c \
	   recursion.c \
	   sort_list.c

SRCO = $(SRCS:.c=.o)

$(NAME):
	make -C libft/
	gcc $(FLAGS) $(NAME) $(SRCS) $(LIB1) $(LIB2) -I=$(HEADER)

all: $(NAME)

san: fclean
	make -C libft/
	gcc -fsanitize=address -g $(FLAGS) $(NAME) $(SRCS) $(LIB1) $(LIB2) -I=$(HEADER)

clean:
	make clean -C libft/
	/bin/rm -f $(SRCO)

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME) *.out* *.dSYM

re: fclean all

git: fclean
	git add .
	git reset HEAD *main*
	git status
	git commit -m "update"
	git push
