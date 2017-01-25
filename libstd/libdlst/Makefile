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
NAME =	libdlst.a

#LIST OF SRC FILES
SRC =   dlst.c \
	dlst_del.c \
	dlst_pos.c \
	dlst_mod.c \
	dlst_itr.c \
	dlst_display.c \
	dlst_str.c \
	dlst_int.c \
	dlst_push.c \
	dlst_insert_sort.c \
	dlst_lnk.c \
	dlst_lnk_cpy.c \
	dlst_lnk_build.c \
	dlst_lnk_del.c \
	dlst_lnk_pos.c \
	dlst_lnk_swap.c \
	dlst_to_array.c

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
	@echo "\033[0;32m> Making libdlst\033[0m"
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
	@echo "\033[0;32m> Libdlst clean.\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
