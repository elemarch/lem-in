#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 05:20:11 by esaminad          #+#    #+#              #
#    Updated: 2015/02/22 22:53:10 by esaminad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##################################################
################## MAIN DEFINES ##################
##################################################
#LIB NAME
NAME =	libstr.a

#LIST OF SRC FILES
SRC =   str_add.c \
	str_data.c \
	str_del.c \
	str_info.c \
	str_link.c \
	str_new.c \
	str_pos.c \
	str_set.c \
	str_size.c \
	str_toc.c

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
	@echo "\033[0;32m> Making libstr\033[0m"
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
	@echo "\033[0;32m> Libstr clean.\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
