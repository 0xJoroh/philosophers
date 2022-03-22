NAME 			= 	philo
COMPILE			= 	gcc -Wall -Werror -Wextra
SRC 			=	main.c src/*.c
OBJS			=	$(SRC:.c=.o)

all: $(NAME)
$(NAME): $(SRC)
	@$(COMPILE) $(SRC) -o $(NAME)

bonus: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
