#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/06 21:39:23 by pbourlet          #+#    #+#             *#
#*   Updated: 2017/03/21 18:34:22 by pbourlet         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = ft_ls

LIB	=	-L. libft/libft.a

LS	=	ft_ls.c \
		ft_testflags.c \
		main.c \
		ft_initls.c \
		ft_joinls.c \
		ft_nlcreate.c \
		ft_strjoinf.c \
		ft_sort.c \
		ft_printls.c \
		ft_opentest.c \
		ft_opentestls.c \
		ft_isdir.c \
		ft_isfile.c \
		ft_printlen.c \
		ft_printall.c \
		ft_sizemax.c \
		ft_printmode.c \
		ft_printacl.c \
		ft_printlnk.c \
		ft_printcolor.c \
		ft_testdir.c \

OBJ	=	$(LS:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc -c -Wall -Wextra -Werror -o $@ -c $< -I./includes 
	@echo "\033[34;01m\xE2\x97\x89 \c"
	@echo "\033[37;01m$<\c"
	@echo "\033[32;01m ✓"
	@echo "\033[0m\c"

$(NAME): $(OBJ)
	@make -C libft/
	@gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	@make -C libft/ clean
	@echo "\033[31mclean ft_ls\c"
	@echo "\033[0m"
	@rm -rf $(OBJ) $(OBJF) $(OBJG)

fclean: clean
	@rm -rf libft/libft.a
	@echo "\033[31mfull clean\c"
	@echo "\033[0m"
	@rm -rf $(NAME)

re: fclean all
