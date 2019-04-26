NAME1 = checker
NAME2 = push_swap
MAIN1 = main_checker.c
MAIN2 = mainpushswap.c
MAIN1O = main_checker.o
MAIN2O = mainpushswap.o 
SRC =  	utils.c \
		sorted.c \
		ft_which_mv.c \
		ft_swap.c \
		ft_push.c \
		ft_moves.c \
		ft_rotate.c \
		ft_rrotate.c \
		ft_atoi_error.c \
		med.c \
		sort.c \
		sort_stacks.c \
		push_back.c \
		small_stacks.c
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
CC = gcc
LIB = libft
LIBDONE = libft/libft.a libft/ft_printf/libftprintf.a
HEADER = includes/push_swap.h

all: libdo $(NAME1) $(NAME2) 

libdo :
	$(MAKE) -C $(LIB)

$(NAME1): $(LIBDONE) $(OBJ) $(MAIN1O) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN1O) $(LIBDONE) -o $(NAME1)

$(NAME2): $(LIBDONE) $(OBJ) $(MAIN2O) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN2O) $(LIBDONE) -o $(NAME2)

$(LIBDONE): libdo

$(OBJ): $(HEADER)

clean:
	rm -f $(OBJ) $(MAIN1O) $(MAIN2O)
	$(MAKE) clean -C $(LIB) 

fclean: clean
	rm -f $(NAME1) $(NAME2)
	$(MAKE) fclean -C $(LIB) 

re: fclean all
