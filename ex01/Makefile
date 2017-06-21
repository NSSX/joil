NAME = serializer

SRCC = main.cpp

SRCO = $(SRCC:%.cpp=%.o)

FLAG = -Wall -Werror -Wextra

all: main

%.o: %.c
	@echo -n  $< :
	@clang++ -o $@ -c $< $(FLAG)
	@echo

main: $(SRCO)
	@clang++ -o $(NAME) $(FLAG) $(SRCO)

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(SRCO) $(NAME)

re: fclean all
