# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:28:58 by jsalmi            #+#    #+#              #
#    Updated: 2020/09/27 12:51:14 by jsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.lib
SRCS = gfx_new_vector.c \
	gfx_draw_vector.c \
	gfx_draw_line.c \
	gfx_vector_dot.c \
	gfx_vector_string.c \
	gfx_draw_rect.c \
	gfx_distance.c \
	gfx_hitbox_square.c \
	gfx_vector_multiply.c \
	shit_from_object_thing.c
OBJS = $(SRCS:.c=.o)
LIBS = libgfx.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -c $(SRCS) $(FLAGS) \
		-I ../better_libui \
		-I ../ft_printf \
		-I ../libft \
		-I ../include/SDL2
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@rm -f $(OBJS)
	@echo "$(NAME) was successfully created."

clean:
	@rm -f $(OBJS)
	@echo "$(NAME) was cleaned."

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, all, fclean, re
