# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/25 15:50:19 by zcarde            #+#    #+#              #
#    Updated: 2015/03/24 09:23:22 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor


SRC = computorv1.c\
insert.c\
list_functions.c\
make_list.c\
math.c\
prints.c\
reduce.c\
soluce1.c\
soluce2.c\
complexes.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra -ggdb3

LIBFT = libft -lft -lncurses

INCLUDES = -I libft/includes

.PHONY : libft.a
# all: libft.a $(NAME)
# 	gcc $(FLAG) $(SRC) $(INCLUDES) -L$(LIBFT) -o $(NAME)
# libft.a:
# 	@$(MAKE) -C ./libft

# $(NAME): $(OBJ)
# 	gcc $(FLAG) $(OBJ) $(INCLUDES) -L$(LIBFT) -o $(NAME)

# %.o: %.c
# 	gcc $(FLAG) $(INCLUDES) -c $^

all: libft.a $(NAME)

libft.a:
	@$(MAKE) -C ./libft

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) $(INCLUDES) -L$(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAG) $(INCLUDES) -c $^

clean :
	@make clean -C ./libft
	rm -f $(OBJ)

fclean : clean
	rm -f libft.a
	rm -f $(NAME)

re : fclean all

