# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simzam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/02 09:58:28 by simzam            #+#    #+#              #
#    Updated: 2016/06/05 11:28:34 by simzam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Werror -Wextra
SRC = fdf.c color.c utils.c display.c draw.c env.c \
		 key_event_handler.c isometric.c parallel.c
OBJ = $(SRC:.c=.o)
MACLIB = -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
LIXLIB = -lm -L libft/ -lft -L/usr/lib/X11 -lmlx -lXext -lX11

all : $(NAME)

.PHONY : linux libft clean fclean re

$(NAME) : libft
	@echo "Manufacturing the Mac OS exec"
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(MACLIB)
	@echo "Done building the Mac OS exec"
linux: libft
	@echo "Manufacturing the Ubuntu OS exec"
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIXLIB)
	@echo "Done building the Ubuntu OS exec"

libft:
	@make -C libft fclean
	@make -C libft

clean :
	@echo "Cleaning the p-code files..."
	@rm -f $(OBJ)
	@echo "Done cleaning the p-code files!"

fclean : clean
	@echo "Removing $(NAME) ..."
	@rm -f $(NAME)

re : fclean all
