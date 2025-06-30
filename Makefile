# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 11:30:00 by luviso-p          #+#    #+#              #
#    Updated: 2025/06/30 10:55:37 by luviso-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = .
OBJDIR = obj

SOURCES = ft_push.c ft_rotate_up.c ft_rotate_down.c ft_swap.c ft_index.c ft_free.c \
          ft_printf/ft_printf.c ft_printf/utils/ft_nbr_hex.c ft_printf/utils/ft_nbr_pointer.c \
          ft_printf/utils/ft_putchar.c ft_printf/utils/ft_putnbr.c ft_printf/utils/ft_putnbru.c \
          ft_printf/utils/ft_putstr.c ft_printf/utils/ft_strlen.c ft_find_index.c ft_sort.c \
		  ft_tools.c test.c ft_find.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

# Colores
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "$(BLUE)Running basic tests...$(NC)"
	@./$(NAME) 4 67 3 87 23
	@echo ""
	@./$(NAME) 2 1 3 6 5 8
	@echo ""
	@./$(NAME) 1 5 2 4 3

test_functions:
	@echo "$(BLUE)Compiling ft_printf...$(NC)"
	@make -C ft_printf
	@echo "$(BLUE)Compiling and running function tests...$(NC)"
	@$(CC) $(CFLAGS) ft_index.c ft_push.c ft_rotate_down.c ft_rotate_up.c ft_swap.c ft_free.c ft_find_index.c ft_sort.c ft_tools.c test.c ft_printf/libftprintf.a -o test_program
	@./test_program
	@rm -f test_program

debug: $(SOURCES)
	@echo "$(BLUE)Compiling with debug info...$(NC)"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(SOURCES) -o $(NAME)_debug

valgrind: $(NAME)
	@echo "$(BLUE)Running valgrind tests...$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 67 3 87 23

norm:
	@echo "$(BLUE)Checking norminette...$(NC)"
	@norminette $(SOURCES) *.h

help:
	@echo "$(GREEN)Available targets:$(NC)"
	@echo "  $(BLUE)all$(NC)           - Build the push_swap program"
	@echo "  $(BLUE)clean$(NC)         - Remove object files"
	@echo "  $(BLUE)fclean$(NC)        - Remove object files and executable"
	@echo "  $(BLUE)re$(NC)            - Rebuild everything"
	@echo "  $(BLUE)test$(NC)          - Run basic functionality tests"
	@echo "  $(BLUE)test_functions$(NC) - Test individual functions"
	@echo "  $(BLUE)debug$(NC)         - Compile with debug and sanitizer"
	@echo "  $(BLUE)valgrind$(NC)      - Run with valgrind memory check"
	@echo "  $(BLUE)norm$(NC)          - Check code with norminette"
	@echo "  $(BLUE)help$(NC)          - Show this help"

.PHONY: all clean fclean re test test_functions debug valgrind norm help
