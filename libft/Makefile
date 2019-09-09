# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 15:12:36 by oryabchu          #+#    #+#              #
#    Updated: 2019/04/16 15:12:40 by oryabchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
GCC		= gcc
FLAGS	= -Wall -Wextra -Werror
SRC		=	ft_printf.c func_for_conversions.c help_func.c help_func_2.c help_func_3.c\
			math_func.c parse.c process_binary.c process_char.c process_charswritten.c\
			process_escape.c process_float.c process_hex.c process_int.c process_long.c\
			process_octal.c process_unsigned.c process_wchar_t_char.c wchar_t_str.c\
			process_null.c\
			ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c\
ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c\
ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstrev.c ft_lstcount.c get_next_line.c ft_splitdel.c\
ft_countwords.c ft_ilerp.c ft_abs.c ft_lerpi.c

OBJ 	= $(SRC:.c=.o)
SRCDIR	= ./srcs/

OBJDIR	= ./objs/

INCDIR	= ./includes/

SRCS	= $(addprefix $(SRCDIR), $(SRC))

OBJS	= $(addprefix $(OBJDIR), $(OBJ))

INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRCS) -I$(INCDIR)
		@mkdir -p $(OBJDIR)
		@mv $(OBJ) $(OBJDIR)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "made" $(NAME)

clean :
	@rm -rf $(OBJS)
	@echo "clean" $(OBJS)
	@rm -rf $(OBJDIR)
	@echo "clean" $(OBJDIR)

fclean : clean
	@rm -rf $(NAME)
	@echo "fclean" $(NAME)

re: fclean all

.PHONY: all clean fclean re
