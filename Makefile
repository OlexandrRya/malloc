# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 14:16:59 by oryabchu          #+#    #+#              #
#    Updated: 2019/04/16 19:51:15 by oryabchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =			libft_malloc_$(HOSTTYPE).so
LINK =			libft_malloc.so
CC =			gcc
FLAGS =			-Wall -Werror -Wextra -fPIC
HEADERS =		-I ./include -I $(LIBFT_DIR)
LIBRARIES =		-L$(LIBFT_DIR) -l$(LIBFT_NAME)
LIBFT_NAME =	ft
LIBFT =			$(LIBFT_DIR)lib$(LIBFT_NAME).a
LIBFT_DIR =		./libft/
SRC_DIR =		./src/

OBJ_DIR_NAME =	obj
OBJ_DIR =		./obj/

FILENAMES =		malloc alloc_mem_func help_func free find realloc show_alloc_mem print_mem

OBJ_PATHS :=	$(addsuffix .o,$(FILENAMES))
OBJ_PATHS :=	$(addprefix $(OBJ_DIR),$(OBJ_PATHS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_PATHS)
	$(CC) $(OBJ_PATHS) $(HEADERS) $(LIBRARIES) -shared -o $(NAME)
	@/bin/rm -f $(LINK)
	ln -s $(NAME) $(LINK)

$(OBJ_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

$(LIBFT):
	(cd $(LIBFT_DIR) && make)


clean:
	-/bin/rm -f $(OBJ_PATHS)
	/usr/bin/find . -name "$(OBJ_DIR_NAME)" -maxdepth 1 -type d -empty -delete
	(cd $(LIBFT_DIR) && make clean)

fclean: clean
	-/bin/rm -f $(NAME) $(LINK)
	(cd $(LIBFT_DIR) && make fclean)
re: fclean all
