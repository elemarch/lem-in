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
NAME =	libft.a

#LIST OF HEADER FILES
HDR  =	libft.h

#LIST OF SRC FILES
SRC  =	ft_atoi.c \
	ft_abs.c \
	ft_bzero.c \
	ft_filcanread.c \
	ft_filsize.c \
	ft_fileopen.c \
	ft_ftoa.c \
	ft_htoi.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isnum.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_intsize.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_pow.c \
	ft_printarr.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putcstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcmplow.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strcmpw.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strrepl.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_swap.c \
	ft_tolower.c \
	ft_toupper.c

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
	@echo "\033[0;32m> Making libft\033[0m"
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
	@echo "\033[0;32m> Libft clean.\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
