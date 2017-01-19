# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 13:28:51 by cbinet            #+#    #+#              #
#    Updated: 2017/01/19 17:22:56 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = srcs/*.c

OBJ = *.o includes/ft_printf/libftprintf.a

FLAGS = -Wall -Wextra -Werror

all: $(SRCS) $(NAME)
	

$(NAME): 
	make -C includes/ft_printf
	gcc -c $(FLAGS) $(SRCS)
	gcc $(FLAGS) -o $(NAME) $(OBJ)
	

clean:
	make clean -C includes/ft_printf
	rm -rf *.o

fclean:clean
	make fclean -C includes/ft_printf
	rm -rf $(NAME)

re:fclean all


.Phony : $(NAME) clean fclean re
