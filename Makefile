NAME = huffman

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS =	huffman.c \
		list.c \
		utils.c \
		main.c 

OUT = $(SRCS:.c=.o)

$(NAME): $(OUT)
		@echo "Objects created."
		@$(CC) $(SRCS) $(OBJS) -o $(NAME)
		@echo "Program created.\n" 
		@./$(NAME)

all: $(NAME)

clean:
		@$(RM) $(OUT) $(OUTB)
		@echo "Objects deleted."

fclean: clean
		@$(RM) $(NAME)
		@echo "Program deleted."

re:		fclean all


.PHONY: all clean fclean re 
