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

#OUTPUT NAME
NAME = libstd.a

#SUB-OUTPUT NAMES
LIBFT   = libft
LIBLST	= liblst
LIBDLST = libdlst
LIBGNL	= libgnl
LIBSTR  = libstr

##################################################################
#You can compile each module separetly by specifying its name :  #
# make libdlst                                                   #
#Or compile everything with:                                     #
# make all                                                       #
##################################################################

##################################################
#################### COMPILE #####################
##################################################
.PHONY: all clean fclean re
#------------------------------------------------
#	              MAIN
#------------------------------------------------
all: $(NAME)

#Build all libs into libstd.a
$(NAME): $(LIBFT).a $(LIBLST).a $(LIBDLST).a $(LIBGNL).a $(LIBSTR).a
	@echo "\033[0;35m[!]> Done.\033[0m"

#Rule for building a .a in its sub directory
%.a:%
	@echo "\033[0;32m> Making $@\033[0m"
	@make -C $^/
	@mv $^/$@ ./

clean:
	@echo "\033[1;31m> Cleaning libs\033[0m"
	@make -C $(LIBFT)/ clean
	@make -C $(LIBLST)/ clean
	@make -C $(LIBDLST)/ clean
	@make -C $(LIBGNL)/ clean
	@make -C $(LIBSTR)/ fclean

fclean:
	@echo "\033[1;31m> Fclean libs\033[0m"
	@make -C $(LIBFT)/ fclean
	@make -C $(LIBLST)/ fclean
	@make -C $(LIBDLST)/ fclean
	@make -C $(LIBGNL)/ fclean
	@make -C $(LIBSTR)/ fclean
	@rm -rf $(LIBFT).a $(LIBLST).a $(LIBDLST).a $(LIBGNL).a $(LIBSTR).a

re: fclean all

.PHONY: all clean fclean re
