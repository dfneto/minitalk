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
SRC = client.c server.c
CFLAGS += -Wextra -Werror -Wall
# This line itself doesn't actually generate the object files; it just sets up the 
# names that will be used when the object files are generated
OBJ = $(SRC:.c=.o)
CC = gcc

################################# RULES ####################################### 
all: $(NAME)

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
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

compile:
	gcc client.c -g -o client
	gcc server.c -g -o server

clean:
	rm -f $(OBJ) *.out client server
	rm -rf *.dSYM

fclean: clean
	rm -f $(NAME)
	rm -f *.gch

re: fclean all

.PHONY: all bonus clean fclean re
