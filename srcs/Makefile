# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 13:36:45 by mdupuis           #+#    #+#              #
#    Updated: 2021/05/17 15:20:02 by mdupuis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR	=	obj/

SRC_DIR	=	srcs/

LIB_DIR	=	libft/

PRINTF_H	=	-I includes/ft_printf.h

LIBFT_H	=	-I libft/libft.h

SRCS	=	ft_printf.c\
			ft_printf_utils.c\
			treat_char.c\
			treat_flags.c\
			treat_hexa.c\
			treat_int.c\
			treat_pointer.c\
			treat_string.c\
			treat_uint.c\
			treat_width.c\
			ft_ulltoa_base.c

NAME	=	libftprintf.a

LIBFT_A	=	libft.a

CC	=	gcc -Wall -Wextra -Werror $(PRINTF_H) $(LIBFT_H) -c -o

CFIND	=	$(SRCS:%=$(SRC_DIR)%)

OFILE	=	$(SRCS:%.c=%.o)

OBJ	=	$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo "ft_printf Objects dir created."

$(NAME): $(OBJ)
				@make -C $(LIB_DIR)
				@echo "Copy $(LIBFT_A) to root."
				@cp $(LIB_DIR)$(LIBFT_A) .
				@mv $(LIBFT_A) $(NAME)
				@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
				@ranlib $(NAME)

$(OBJ): $(CFIND)
				@$(MAKE) $(OFILE)

$(OFILE):
				@$(CC) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
				@/bin/rm -rf $(OBJ_DIR)
				@make -C $(LIB_DIR) clean
				@echo "ft_printf object file Cleaned !"

fclean: clean
				@/bin/rm -f $(NAME)
				@make -C $(LIB_DIR) fclean
				@echo "Cleaned $(NAME)"

re: fclean all

.PHONY: all clean flcean re

