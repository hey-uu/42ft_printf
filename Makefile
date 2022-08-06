# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 20:08:04 by hyeyukim          #+#    #+#              #
#    Updated: 2022/08/06 10:27:23 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -f

FILES = ft_libft_fcts \
		ft_printf \
		ft_printf_utils \
		put_characters \
		put_integers \
		put_integers_utils \

SRCS = $(addsuffix .c, $(FILES))
OBJCS = $(addsuffix .o, $(FILES))

$(NAME) : $(OBJCS)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJCS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus