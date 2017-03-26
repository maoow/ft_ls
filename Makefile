# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 13:28:51 by cbinet            #+#    #+#              #
#    Updated: 2017/03/19 14:58:09 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_PATH = srcs/
SRC_NAME = ft_display.c ft_ls.c ft_lssort.c ft_lstab.c \
		   ft_freels.c ft_lssets.c ft_lsfileset.c ft_lslongset.c\
		   ft_lssortdir.c ft_lsaddfile.c ft_lswidth.c ft_lsgeneralssets.c
OBJ_NAME = ft_display.o ft_ls.o ft_lssort.o ft_lstab.o \
		   ft_freels.o ft_lssets.o ft_lsfileset.o \
		   ft_lslongset.o ft_lssortdir.o ft_lsaddfile.o ft_lswidth.o ft_lsgeneralssets.o
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

PRINTF_PATH = includes/ft_printf/srcs/
PRINTF_NAME = ft_printf.c convarg.c ft_buffit.c ft_colorize.c \
			  ft_getbases.c ft_getbases2.c ft_getf.c ft_getnbr.c \
			  ft_gets.c ft_getsstr.c ft_getwchars.c ft_placeit.c \
			  ft_putbuf.c ft_setflags.c ft_flagit.c ft_getcursor.c \
			  ft_getbool.c ft_getstrptr.c ft_gettime.c ft_timeset.c
PRINTFO_NAME = ft_printf.o convarg.o ft_buffit.o ft_colorize.o \
			   ft_getbases.o ft_getbases2.o ft_getf.o ft_getnbr.o \
			   ft_gets.o ft_getsstr.o ft_getwchars.o ft_placeit.o \
			   ft_putbuf.o ft_setflags.o ft_flagit.o ft_getcursor.o \
			   ft_getbool.o ft_getstrptr.o ft_gettime.o ft_timeset.o

LIB_PATH = includes/ft_printf/srcs/libft/
LIB_SRC = ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstputstr.c \
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

OBJ_PATH = obj/
LIBO_PATH = obj/
PRINTFO_PATH = obj/

INCLUDES = includes/ft_printf/srcs/libft/libft.h includes/ft_printf.h 





PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_SRCS))
LIBO = $(addprefix $(LIBO_PATH), $(LIB_OBJ))
PRINTFO = $(addprefix $(PRINTFO_PATH), $(PRINTFO_NAME))

FLAG = -Wall -Wextra -Werror -Ofast

all: $(NAME) $(INCLUDES)

$(NAME): $(OBJ) $(LIBO) $(PRINTFO)
	@gcc $(FLAG) $^ -o $(NAME) 
	@echo -n $(NAME)
	@echo " updated !"

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir obj

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	gcc -c $(FLAG) -o $@ -c $<

$(LIBO): | $(LIBO_PATH)


$(LIBO_PATH)%.o: $(LIB_PATH)%.c includes
	gcc -c $(FLAG) -o $@ -c $<

$(PRINTFO): | $(PRINTFO_PATH)


$(PRINTFO_PATH)%.o: $(PRINTF_PATH)%.c
	gcc -c $(FLAG) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Folder cleaned !"

fclean:clean
	@rm -rf $(NAME)
	@echo -n $(NAME)
	@echo " deleted !"

re: fclean
	make

.Phony : clean fclean re all
