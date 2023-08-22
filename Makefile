# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifern <davifern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 13:18:58 by davifern          #+#    #+#              #
#    Updated: 2023/08/17 13:19:00 by davifern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



########################## VARIABLES DEFINITIONS ###############################
HEADER = push_swap.h
SRC = src/client.c src/server.c src/utils.c
DIR_LIBFT = ./deps/libft/
LIBFT = $(DIR_LIBFT)/libft.a
DIR_PRINTF = ./deps/ft_printf/
PRINTF = $(DIR_PRINTF)/libftprintf.a

CFLAGS += -Wextra -Werror -Wall
# This line itself doesn't actually generate the object files; it just sets up the 
# names that will be used when the object files are generated
# OBJ = $(SRC:.c=.o)
CC = gcc

################################# RULES ####################################### 
all: MAKE_LIBFT MAKE_PRINTF $(NAME)

# -C <path> option. This changes the current path to the path '<path>'
MAKE_LIBFT:
	@echo compiling libft ...
	@make -C $(DIR_LIBFT)

MAKE_PRINTF:
	@echo compiling ft_printf ...
	@make -C $(DIR_PRINTF)

CLEAN_LIBFT:
	@echo cleaning libft ...
	@make clean -C $(DIR_LIBFT)

CLEAN_PRINTF:
	@echo cleaning printf ...
	@make clean -C $(DIR_PRINTF)

# This pattern rule tells make how to build a .o file from a corresponding .c file 
# (and ensures that the object files are recompiled if the header file, indicated 
# by $(HEADER), changes). It specifies that the command $(CC) $(CFLAGS) -c $< -o $@ 
# should be used to compile each .c file into a corresponding .o file.
# This is a pattern rule that specifies how to build an object file (.o) from a 
# corresponding source file (.c). It also depends on the $(HEADER) file, meaning the
# object files will be recompiled if the header file changes.
# $(CC) $(CFLAGS) -c $< -o $@: This is the command that actually compiles each .c 
# file into an .o file. $< is the first dependency (the .c file in this case) and $@ 
# is the target (the .o file).
# %.o : %.c $(HEADER)
#	$(CC) $(CFLAGS) -c $< -o $@

compile:
# 	gcc client.c -g -o client
	@echo 'compiling ...' 
	@gcc $(LIBFT) $(PRINTF) -g src/utils.c src/server.c -o server
	@gcc $(LIBFT) $(PRINTF) -g src/utils.c src/client.c -o client

# run: compile
# 	@echo running ...
# 	@./server
# 	@./client

clean: CLEAN_LIBFT CLEAN_PRINTF
	rm -f $(OBJ) *.out client server
	rm -rf *.dSYM
	
fclean: clean
	rm -f $(NAME)
	rm -f *.gch

re: fclean all

.PHONY: all bonus clean fclean re
