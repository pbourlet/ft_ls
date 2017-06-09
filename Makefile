#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/06 21:39:23 by pbourlet          #+#    #+#             *#
#*   Updated: 2017/06/09 18:02:29 by pbourlet         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = ft_ls

LIB	=	-L. ~/libft/libft.a

INC =	$(addprefix ~/libft/, \
		includes/libft.h \
		includes/get_next_line.h \
		includes/ft_printf.h \
		ft_printf/ft_printf.h \
		get_next_line/get_next_line.h\
		) \
		includes/ft_ls.h \

SRCDIR =	src

OBJDIR =	obj

LS	=	\
		ft_testflags.c \
		main.c \
		ft_initls.c \
		ft_joinls.c \
		ft_nlcreate.c \
		ft_strjoinf.c \
		ft_sort.c \
		ft_printls.c \
		ft_isfile.c \
		ft_printlen.c \
		ft_printall.c \
		ft_sizemax.c \
		ft_printmode.c \
		ft_printacl.c \
		ft_printlnk.c \
		ft_printcolor.c \
		ft_printblks.c \
		ft_testdir.c \
		ft_recursif.c \
		ft_error.c \
		ft_testarg.c \
		ft_lssize.c \
		ft_printtime.c \
		ft_printtag.c \

OBJ	=	$(LS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): dir $(OBJ)
	@make -C ~/libft/
	@gcc -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[34;01m===== \c"
	@echo "\033[32;01mEXE CREATED\c"
	@echo "\033[0m\033[34;01m   =====\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	@gcc -c -Wall -Wextra -Werror -o $@ -c $< -I./includes 
	@echo "\033[34;01m\xE2\x97\x89 \c"
	@echo "\033[37;01m$(notdir $(basename $<))\c"
	@echo "\033[32;01m ✓"
	@echo "\033[0m\c"

dir:
	@mkdir -p $(OBJDIR)

clean:
	@make -C ~/libft/ clean
	@echo "\033[31m===== \c"
	@echo "\033[0m\033[32;01mDIR CLEAN\c"
	@echo "\033[0m\033[31m     =====\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf ~/libft/libft.a
	@echo "\033[31m===== \c"
	@echo "\033[0m\033[32;01mFT_LS CLEAN\c"
	@echo "\033[0m\033[31m   =====\033[0m"
	@rm -rf $(NAME)

re: fclean all
