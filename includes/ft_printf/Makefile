# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 14:45:18 by cbinet            #+#    #+#              #
#    Updated: 2017/03/09 14:42:33 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -g

NAME = libftprintf.a

PRINTF_PATH = includes/ft_printf/srcs/

PRINTF_NAME = ft_printf.c convarg.c ft_buffit.c ft_colorize.c \
		   ft_getbases.c ft_getbases2.c ft_getf.c ft_getnbr.c \
		   ft_gets.c ft_getsstr.c ft_getwchars.c ft_placeit.c \
		   ft_putbuf.c ft_setflags.c ft_flagit.c ft_getcursor.c \
		   ft_getbool.c ft_getstrptr.c ft_gettime.c ft_timeset.c

INCLUDES = libft.h includes/ft_printf.h

PRINTFO_PATH = includes/ft_printf/obj/
PRINTFO_NAME = ft_printf.o convarg.o ft_buffit.o ft_colorize.o \
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstputstr.c \
	  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	  ft_putendl.c ft_putendl_fd.c ft_putlnbrbase.c ft_putnbr.c ft_putnbr_fd.c \
	  ft_putnbrbase.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	  ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	  ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	  ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	  ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
	  ft_lstaddend.c ft_toupper.c ft_itoabase.c ft_litoabase.c ft_tablen.c \
	  ft_litoa.c ft_umitoa.c ft_mitoa.c ft_ulitoa.c ft_uitoa.c ft_llitoa.c

LIB_OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
		  ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o \
		  ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_lstputstr.o \
		  ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
		  ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
		  ft_putendl.o ft_putendl_fd.o ft_putlnbrbase.o ft_putnbr.o ft_putnbr_fd.o \
		  ft_putnbrbase.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o \
		  ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o \
		  ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
		  ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o \
		  ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o \
		  ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o \
		  ft_lstaddend.o ft_toupper.o ft_itoabase.o ft_litoabase.o ft_tablen.o \
		  ft_litoa.o ft_umitoa.o ft_mitoa.o ft_ulitoa.o ft_uitoa.o ft_llitoa.o

PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_SRCS))
LIBO = $(addprefix $(LIB_PATH), $(LIB_OBJ))
PRINTFO = $(addprefix $(PRINFO_PATH), $(PRINTFO_NAME))


FLAG = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(LIBO)
	@ar rc $(NAME) $(OBJ) $(LIBO) 
	@ranlib $(NAME)
	@echo -n $(NAME)
	@echo " updated !"


clean:
	@rm -rf $(OBJ_PATH) $(LIBO)
	@echo "Folder cleaned !"

fclean:clean
	@rm -rf $(NAME)
	@echo -n $(NAME)
	@echo " deleted !"

re:fclean all

