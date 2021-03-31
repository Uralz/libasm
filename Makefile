NAME = libasm.a
CC = clang
SRC = 	ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s

OBJ = $(SRC:.s=.o)

%.o: src/%.s
	nasm -felf64 $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(addprefix src/, $(OBJ))

test: re
	clang -L. main.c -lasm

clean:
	rm -f $(addprefix src/, $(OBJ))
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re test