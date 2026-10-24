NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

SRCS = ftput.c \
       ft_printf.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all
