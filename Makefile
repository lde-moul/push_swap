# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 14:29:01 by lde-moul          #+#    #+#              #
#    Updated: 2017/06/14 18:35:03 by lde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = objs


NAME_CHECKER = checker

DIR_CHECKER = checker
SRCDIR_CHECKER = $(SRCDIR)/$(DIR_CHECKER)
OBJDIR_CHECKER = $(OBJDIR)/$(DIR_CHECKER)

SRCBASE_CHECKER = main.c\
				  unsorted_stack.c\
				  instructions.c\
				  sort_stack.c\
				  swap.c\
				  push.c\
				  rotate.c\
				  reverse_rotate.c\

SRC_CHECKER = $(SRCBASE_CHECKER:%=$(SRCDIR_CHECKER)/%)
OBJ_CHECKER = $(SRCBASE_CHECKER:%.c=$(OBJDIR_CHECKER)/%.o)


NAME_PUSHSWAP = push_swap

DIR_PUSHSWAP = push_swap
SRCDIR_PUSHSWAP = $(SRCDIR)/$(DIR_PUSHSWAP)
OBJDIR_PUSHSWAP = $(OBJDIR)/$(DIR_PUSHSWAP)

SRCBASE_PUSHSWAP = main.c\
				   unsorted_stack.c\
				   instructions.c\
				   split_stack.c\
				   sort_stack.c\
				   push.c\
				   rotate.c\
				   reverse_rotate.c\
				   swap.c\
				   stack.c\

SRC_PUSHSWAP = $(SRCBASE_PUSHSWAP:%=$(SRCDIR_PUSHSWAP)/%)
OBJ_PUSHSWAP = $(SRCBASE_PUSHSWAP:%.c=$(OBJDIR_PUSHSWAP)/%.o)


DIR_LIBFT = libft
NAME_LIBFT = $(DIR_LIBFT)/libft.a
INC_LIBFT = $(DIR_LIBFT)/includes


.PHONY: all clean fclean re

all: $(NAME_CHECKER) $(NAME_PUSHSWAP)

clean:
	/bin/rm -f $(OBJ_LIBFT)
	/bin/rm -f $(OBJ_CHECKER)
	/bin/rm -f $(OBJ_PUSHSWAP)

fclean: clean
	/bin/rm -f $(NAME_LIBFT)
	/bin/rm -f $(NAME_CHECKER)
	/bin/rm -f $(NAME_PUSHSWAP)

re: fclean all

$(OBJDIR):
	/bin/mkdir $(OBJDIR)


$(NAME_CHECKER): $(NAME_LIBFT) $(OBJDIR_CHECKER) $(OBJ_CHECKER)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CHECKER) $(NAME_LIBFT)

$(OBJDIR_CHECKER)/%.o: $(SRCDIR_CHECKER)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INC_LIBFT)

$(OBJDIR_CHECKER): $(OBJDIR)
	/bin/mkdir $(OBJDIR_CHECKER)


$(NAME_PUSHSWAP): $(NAME_LIBFT) $(OBJDIR_PUSHSWAP) $(OBJ_PUSHSWAP)
	$(CC) $(CFLAGS) -o $@ $(OBJ_PUSHSWAP) $(NAME_LIBFT)

$(OBJDIR_PUSHSWAP)/%.o: $(SRCDIR_PUSHSWAP)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INC_LIBFT)

$(OBJDIR_PUSHSWAP): $(OBJDIR)
	/bin/mkdir $(OBJDIR_PUSHSWAP)


$(NAME_LIBFT):
	make -C $(DIR_LIBFT)
