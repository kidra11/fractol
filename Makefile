# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsion <nsion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 10:28:49 by nsion             #+#    #+#              #
#    Updated: 2023/07/24 19:02:52 by nsion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = burning_ship.c mandelbrot.c julia.c macro.c fractol.c ft_printf/ft_printf.c  ft_printf/ft_find.c

NAME = fractol

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = $(SRCS:.c=.o)

LMLX = mlx/libmlx.a

LIB = -Lmlx/ -lmlx -L/usr/lib/ -lXext -lX11 -lm -I ./ -I ./mlx/

all	: $(LMLX) $(NAME)

${LMLX}	:
	make -C mlx/ all

.c.o	:
	$(GCC) $(CFLAGS) $(LIB) -c $< -o $(<:.c=.o) 

$(NAME) : $(OBJS)
	$(GCC) $(OBJS) $(LIB) -o $(NAME)

clean	:
	$(RM) $(OBJS)
	make -C mlx clean

fclean	:	clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re

