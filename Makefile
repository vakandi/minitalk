GCCFLAG=-Wall -Wextra -Werror
NAME = server
NAME2 = client

all: $(NAME) $(NAME2)

$(NAME): server.c
	@echo "\033[1;35m\n\n - STARTING COMPILATION OF SERVER -\n\n\033[0m"	
	cc $(GCCFLAG) server.c -o $(NAME)

$(NAME2): client.c
	@echo "\033[1;35m\n\n - STARTING COMPILATION OF CLIENT -\n\n\033[0m"	
	cc $(GCCFLAG) client.c -o $(NAME2)
	
clean: fclean

fclean: 
	@/bin/rm -f client
	@/bin/rm -f server

re: fclean all
