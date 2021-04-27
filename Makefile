NAME = libasm.a
CC = clang
SRC = 	ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s

OBJ = $(SRC:.s=.o)

%.o: %.s
	nasm -f macho64 $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): libasm.h

test: re
	$(CC) -L. main.c -lasm

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	rm -f a.out
re: fclean all

.PHONY: all clean fclean re test