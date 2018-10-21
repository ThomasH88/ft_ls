# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2018/10/04 16:55:59 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = b_ls

HEADER = libft.h

FLAGS = -Wall -Werror -Wextra -o

FSAN = -fsanitize=address -g

SRC = srcs/*.c 

SRCO = *.o

INCLUDES = includes/

$(NAME):
	gcc  $(FLAGS) $(NAME) $(SRC) -I $(INCLUDES)
all: $(NAME)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -rf $(NAME) *.out *.dSYM

re: fclean all

san: fclean 
	gcc $(FSAN) $(FLAGS) $(NAME) $(SRC) -I $(INCLUDES)

git: fclean
	git add .
	git reset HEAD .*
	git reset HEAD cheat_sheet.c
	git status
	git commit -m "yeah"
