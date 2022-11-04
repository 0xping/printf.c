CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utilities.c mini_libft.c
SRC_BONUS = ft_printf_bonus.c ft_printf_utilities.c mini_libft.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)


NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc	 $(NAME) $(OBJ)

bonus : $(OBJ_BONUS)
	@rm -rf $(NAME)
	ar -rc	 $(NAME) $(OBJ_BONUS)

clean :
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean bonus all re
