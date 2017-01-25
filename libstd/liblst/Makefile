#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#              #
#    Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##################################################
################## MAIN DEFINES ##################
##################################################
#LIB NAME
NAME =	liblst.a

#LIST OF HEADER FILES
HDR  =	liblst.h

#LIST OF SRC FILES
SRC  =	lst_add.c\
	lst_clear.c\
	lst_cpy.c\
	lst_del.c\
	lst_delone.c\
	lst_iter.c\
	lst_map.c\
	lst_new.c\
	lst_push.c\
	lst_rev.c

##################################################
#################DEFINE SOME SHIT#################
##################################################
CFLAGS	= -Wall -Werror -Wextra
CC	= clang
OBJ	= $(SRC:.c=.o)
INC	= -I ../includes

##################################################
################COMPILE THAT SHIT#################
##################################################
.PHONY: all clean fclean re
all:
	@echo "\033[0;32m> Making liblst\033[0m"
	@make $(NAME)

%.o: %.c
	@printf "\033[1;36mCompile \e[33m%-41s\e[0m" "$<"
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $^
	@printf "\033[1;32m[✔]\033[0m\n"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0;32m> Done.\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[0;32m> liblst clean.\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
