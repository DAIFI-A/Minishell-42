# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 17:41:58 by med-doba          #+#    #+#              #
#    Updated: 2022/08/25 19:23:50 by adaifi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOM = libft.a

CC = gcc

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

FCT =	ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c \
		ft_putnbr_fd.c ft_substr.c \
		ft_putstr_fd.c ft_strlen.c \
		ft_memcpy.c ft_split.c \
		ft_strdup.c ft_isdigit.c \
		ft_putchar_fd.c ft_strjoin.c ft_strcmp.c\
		ft_strjoin_custom.c ft_strchr.c ft_strlcpy.c\
		ft_isalpha.c ft_memmove.c ft_isalnum.c ft_strncmp.c\

OBJ = $(FCT:.c=.o)

$(NOM): $(OBJ) 
	@ar -rc $(NOM) $(OBJ)

%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NOM)

re: fclean all

all: $(NOM)
