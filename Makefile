NAME = libftprintf.a

SRCS = ft_printf.c \
       print_c.c \
       print_d_i.c \
	   print_p.c \
	   print_s.c \
	   print_u.c \
	   print_x.c \
	   print_per.c \
	   utils.c 

LIBFT = libft

LIBFT_LIB = libft.a

INCS = .

OBJS = $(SRCS:.c=.o)

RM = rm -f

LIBC = ar rc

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME):$(OBJS)
	make all -C $(LIBFT)/
	cp ./$(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)
	
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: libft clean fclean all re