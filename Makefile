# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 13:29:02 by sdelhomm          #+#    #+#              #
#    Updated: 2018/03/20 14:02:38 by tgunzbur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_map.c \
	  main.c \
	  raycasting.c \
	  events.c \
	  check_fcts.c \
	  key_hook_fcts.c \
	  draw.c \
	  show_menu.c \
	  free_map.c \
	  ft_init.c \
	  load_texture.c \

SRCPATH = ./srcs/

OBJ = $(SRC:.c=.o)

LIB = libft.a

LIBPATH = ./libft/

DLLPATH = ./libfmod.dylib

NAME = wolf3d

FLAGS = -O3 -Wall -Werror -Wextra

all : $(NAME)
$(NAME) :
	@make -C $(LIBPATH)
	@gcc -c $(FLAGS) $(addprefix $(SRCPATH),$(SRC))
	@echo "\033[33;32m[Create objects]\t\t\t[ ✓ ]"
	@gcc $(DLLPATH) -o $(NAME) $(FLAGS) $(OBJ) $(LIBPATH)$(LIB) -lmlx -framework OpenGL -framework AppKit
	@echo "\033[33;32m[Create $(NAME)]\t\t\t\t[ ✓ ]"
	@install_name_tool -change @loader_path/../Frameworks/libfmodex.dylib $(DLLPATH) $(NAME)
	@echo "\033[33;32m[DyLib linked]\t\t\t\t[ ✓ ]"

clean :
	@make clean -C $(LIBPATH)
	@rm -f $(OBJ)
	@echo "\033[33;32m[Clean objects]\t\t\t\t[ ✓ ]"

fclean : clean
	@rm -f $(LIBPATH)$(LIB)
	@rm -f $(NAME)
	@echo "\033[33;32m[Clean $(NAME)]\t\t\t\t[ ✓ ]"

re : fclean all
