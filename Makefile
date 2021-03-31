NAME = libasm.a
CC = clang
SRC = 	ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s

OBJ = $(SRC: *.s = *.o)

%.o: %.s
	nasm -felf64 $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
#	ranlib $(NAME)

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re