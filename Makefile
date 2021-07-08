# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:28:58 by jsalmi            #+#    #+#              #
#    Updated: 2021/05/06 12:36:12 by jsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.a
SRCS = gfx_new_vector.c \
	gfx_draw_vector.c \
	gfx_draw_line.c \
	gfx_vector_dot.c \
	gfx_vector_string.c \
	gfx_draw_rect.c \
	gfx_distance.c \
	gfx_hitbox_square.c \
	gfx_vector_multiply.c \
	gfx_vector_divide.c \
	gfx_vector_add.c \
	gfx_vector_sub.c \
	gfx_vector_copy.c \
	ft_create_circle.c \
	ft_create_line.c \
	shit_from_object_thing.c

OBJS = $(SRCS:.c=.o)
LIBS = libgfx.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -c $(SRCS) $(FLAGS) \
		-I../libft \
		-I../better_libui \
		-I../SDL2/includes \
		-I../ft_printf
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) was successfully created."

clean:
	@rm -f $(OBJS)
	@echo "$(NAME) was cleaned."

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, all, fclean, re

