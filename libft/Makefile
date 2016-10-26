NAME = libft.a
PATH_SRC = ./src/
HEADER = ./
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = ft_atoi.c ft_bzero.c ft_itoa.c \
ft_mem{alloc,ccpy,chr,cmp,cpy,del,move,set}.c \
ft_put{char,char_fd,endl,endl_fd,nbr_fd,str,str_fd}.c \
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
ft_strdup.c ft_strequ.c \
ft_str{iter,iteri}.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
ft_str{map,mapi}.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strdup.c ft_strnequ.c ft_strnew.c \
ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
ft_strtrim.c ft_to{lower,upper}.c \
ft_lst{add,del,delone,iter,map,new}.c \
ft_is{alnum,alpha,ascii,digit,print}.c

OBJ = $(SRC:.c=.o)
all: $(NAME) clean

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
