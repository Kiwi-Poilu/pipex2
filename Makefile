NAME = pipex

INC = include 

SRCS =	srcs/pipex.c \
		srcs/utils.c \
		srcs/ft_split.c \
		srcs/ft_strjoin.c \
		srcs/utils2.c \
		srcs/cmd.c

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -g3 -Wall -Werror -Wextra

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

run : all
		./pipex

debug : all
		valgrind ./pipex