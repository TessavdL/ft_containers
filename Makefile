# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tevan-de <tevan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/24 11:37:21 by tevan-de      #+#    #+#                  #
#    Updated: 2021/08/19 14:10:47 by tevan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC			=	g++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

NAME		=	ft_containers

SRCS		=	main_map.cpp

SRCS_DIR	=	./srcs/

OFILES		=	$(addprefix $(SRCS_DIR), $(SRCS:%.cpp=%.o))

INCLUDES	=	-I ./includes/

ifeq ($(DEBUG),1)
	CFLAGS += -g -fsanitize=address
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OFILES) -o $(NAME)
	@echo "Executable created..."

%.o: %.c $(INCLUDES)
	@echo "Compiling... $^"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

clean:
	@echo "Cleaning..."
	@rm -f $(OFILES)

fclean: clean
	@echo "Extra cleaning..."
	@rm -f $(NAME)

re: fclean all
