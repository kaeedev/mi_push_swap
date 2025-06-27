# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 11:30:00 by luviso-p          #+#    #+#              #
#    Updated: 2025/06/27 11:34:01 by luviso-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = .
OBJDIR = obj

SOURCES = 

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

.PHONY: all clean fclean re test
