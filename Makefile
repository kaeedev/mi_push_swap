# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 11:30:00 by luviso-p          #+#    #+#              #
#    Updated: 2025/07/05 10:37:04 by lalbe            ###   ########.fr        #
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
          ft_tools.c ft_find.c ft_sort_big.c ft_sort_c.c ft_moves.c ft_atoi.c ft_pos.c \
		  ft_push_swap.c ft_chunks.c
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

# Colores
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
NC = \033[0m

all: $(NAME)

# Crear directorios necesarios
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/ft_printf
	@mkdir -p $(OBJDIR)/ft_printf/utils

# Regla para compilar archivos .c en el directorio raíz
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Regla específica para archivos de ft_printf
$(OBJDIR)/ft_printf/%.o: ft_printf/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Regla específica para archivos de ft_printf/utils
$(OBJDIR)/ft_printf/utils/%.o: ft_printf/utils/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(NC)"

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJDIR)
	@echo "$(RED)Cleaning ft_printf...$(NC)"
	@make -C ft_printf clean

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)Cleaning ft_printf library...$(NC)"
	@make -C ft_printf fclean

re: fclean all

test: $(NAME)
	@echo "$(BLUE)Running basic tests...$(NC)"
	@./$(NAME) 4 67 3 87 23
	@echo ""
	@./$(NAME) 2 1 3 6 5 8
	@echo ""
	@./$(NAME) 1 5 2 4 3

debug: $(SOURCES)
	@echo "$(BLUE)Compiling with debug info...$(NC)"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(SOURCES) -o $(NAME)_debug

valgrind: $(NAME)
	@echo "$(BLUE)Running valgrind tests...$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 67 3 87 23

norm:
	@echo "$(BLUE)Checking norminette...$(NC)"
	@norminette $(SOURCES) *.h

.PHONY: all clean fclean re test test_functions debug valgrind norm help
