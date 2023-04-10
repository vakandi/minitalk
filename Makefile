GCCFLAG=-Wall -Wextra -Werror

all: 
	@clear
	@echo "\033[35m	 /$$      /$$ /$$           /$$   /$$               /$$ /$$      \033[0m"
	@echo "\033[35m| $$$    /$$$|__/          |__/  | $$              | $$| $$      \033[0m"
	@echo "\033[35m| $$$$  /$$$$ /$$ /$$$$$$$  /$$ /$$$$$$    /$$$$$$ | $$| $$   /$$\033[0m"
	@echo "\033[35m| $$ $$/$$ $$| $$| $$__  $$| $$|_  $$_/   |____  $$| $$| $$  /$$/\033[0m"
	@echo "\033[35m| $$  $$$| $$| $$| $$  \ $$| $$  | $$      /$$$$$$$| $$| $$$$$$/ \033[0m"
	@echo "\033[35m| $$\  $ | $$| $$| $$  | $$| $$  | $$ /$$ /$$__  $$| $$| $$_  $$ \033[0m"
	@echo "\033[35m| $$ \/  | $$| $$| $$  | $$| $$  |  $$$$/|  $$$$$$$| $$| $$ \  $$\033[0m"
	@echo "\033[35m|__/     |__/|__/|__/  |__/|__/   \___/   \_______/|__/|__/  \__/\033[0m"
	@sleep 5s
	@clear
	@echo "\033[1;35m\n\n - STARTING COMPILATION OF CLIENT -\n\n\033[0m"	
	gcc $(GCCFLAG) -c client.c
	@if [ -f client ]; then echo "\033[1;32m\n\n - COMPILATION FINISHED -\n\n\033[0m"; echo "\033[1;34m\n\n  Name of the executable: \n\033[1;34m        client\n\n\033[0m"; else echo "\033[1;31m\n\n - COMPILATION FAILED -\n\n\033[0m"; fi
	gcc $(GCCFLAG) -c server.c
	@echo "\033[1;35m\n\n - STARTING COMPILATION OF SERVER -\n\n\033[0m"	
	@if [ -f server ]; then echo "\033[1;32m\n\n - COMPILATION FINISHED -\n\n\033[0m"; echo "\033[1;34m\n\n  Name of the executable: \n\033[1;34m        server\n\n\033[0m"; else echo "\033[1;31m\n\n - COMPILATION FAILED -\n\n\033[0m"; fi
clean:
	@/bin/rm *.o

fclean: clean
	@/bin/rm -f client
	@/bin/rm -f server

re: fclean all
