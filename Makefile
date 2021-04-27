# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:28:58 by jsalmi            #+#    #+#              #
#    Updated: 2021/04/26 11:03:30 by jsalmi           ###   ########.fr        #
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
	ft_create_circle.c \
	ft_create_line.c \
	shit_from_object_thing.c
OBJS = $(SRCS:.c=.o)
LIBS = libgfx.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@gcc -c $(SRCS) $(FLAGS) \
		-I ../better_libui-windows \
		-I ../ft_printf-windows \
		-I ../libft-windows \
		-I ../include
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
