NAME = cub3d

SRCS = \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wextra -Werror -Wall

CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

%.o :%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
