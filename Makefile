NAME 			= 	philo
COMPILE			= 	gcc -Wall -Werror -Wextra
SRC 			=	*.c
OBJS			=	$(SRC:.c=.o)
# SRC_BONUS		=
# OBJS_BONUS	= $(SRC_BONUS:.c=.o)

all: $(NAME)
$(NAME): $(SRC)
	@$(COMPILE) $(SRC) -o $(NAME)

bonus: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
