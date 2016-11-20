# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 18:22:46 by lasalced          #+#    #+#              #
#    Updated: 2016/11/20 09:54:09 by lasalced         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		main.c \
				fonctiontab.c \
				utilitaire.c \
				parser.c \
				findcost.c \

OBJ		=		$(SRC:.c=.o)

LIB		=		libft/libft.a

INC		=		libft/includes

NAME	=		lasalced.filler

RM		=		rm -f

FLAG	=		-Wall -Werror -Wextra

all: libft.a $(NAME)

$(NAME): $(OBJ)
		gcc -g $(FLAG) -c $(SRC)  -I $(INC)
		gcc -o $(NAME) $(OBJ) -L. $(LIB) -g

libft.a:
		make -C libft/

re:		fclean all

clean:
		@$(RM) $(OBJ)
		make -C libft/ clean

fclean:
		@$(RM) $(OBJ) $(NAME)
		make -C libft/ fclean
		@$(RM) libft.h.gch

.PHONY: clean fclean re
