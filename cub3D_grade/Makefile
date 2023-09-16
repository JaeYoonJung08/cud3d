# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 19:21:21 by jaeyojun          #+#    #+#              #
#    Updated: 2023/09/16 17:54:32 by jaeyojun         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = CC
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./mlx
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS = main.c error_free.c read_map.c get_direction.c set_rgb.c\
		check_map.c check_wall.c check_zero.c check_overlap.c\
		str/str.c str/split.c str/str2.c\
		dda.c keyhook.c render.c init.c texture.c\

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	
$(NAME) : $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX)

clean :
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	
re : fclean all

bonus : all

.PHONY: all clean fclean re
