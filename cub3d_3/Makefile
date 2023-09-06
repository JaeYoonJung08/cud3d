# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 19:21:21 by jaeyojun          #+#    #+#              #
#    Updated: 2023/09/06 18:07:45 by jaeyojun         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = CC
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS = cub3d.c cub3d_error_free.c cub3d_read_map.c cub3d_direction.c cub3d_rgb.c\
		cub3d_check_map.c\
		str/str.c str/split.c
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

.PHONY: clean fclean re
