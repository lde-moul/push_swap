# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 11:29:42 by lde-moul          #+#    #+#              #
#    Updated: 2017/05/24 15:00:01 by lde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes

SRCBASE = ft_strlen.c \
		  ft_strcmp.c \
		  ft_atoi.c \
		  ft_isdigit.c \
		  ft_strsplit.c \

SRC = $(SRCBASE:%=$(SRCDIR)/%)
OBJ = $(SRCBASE:%.c=$(OBJDIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

%.c:
	@/bin/echo $@ does not exist.

$(OBJDIR):
	@/bin/mkdir $(OBJDIR)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
