#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboddez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/09 12:57:20 by kboddez           #+#    #+#              #
#    Updated: 2017/01/16 18:00:57 by kboddez          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

MAIN = main.c

SRC_NAME =  $(MAIN) dsh_computer.c dsh_parse.c dsh_cmd.c dsh_cmd_exe.c \
	dsh_echo.c dsh_env.c dsh_setenv.c dsh_unsetenv.c dsh_reset_env.c \
	dsh_error.c dsh_free_viag.c dsh_getenv.c dsh_cd.c dsh_tilde.c

GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
WHITE = \033[37m

SRC_PATH = ./srcs/

INC_PATH = ./include/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

CFLAGS = -Wall -Wextra -Werror -Ofast

OBJ = $(SRC:.c=.o)

LIB_PRINTF = ./ft_printf/libftprintf.a
LIB_FT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Compilation libft\t:\t"
	@make -C ./libft re
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Compilation printf\t:\t"
	@make -C ./ft_printf re
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Compilation shell\t:\t"
	@gcc $(SRC) $(LIB_FT) $(LIB_PRINTF) -o $(NAME)
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="

%.o : %.c
	@gcc -o $@ -c $< -I $(INC_PATH)

clean:
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Clean\t\t:\t"
	@make -C ./libft clean
	@make -C ./ft_printf clean
	@/bin/rm -f $(OBJ)
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="

fclean: clean
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)FClean\t\t:\t"
	@make -C ./libft fclean
	@make -C ./ft_printf fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f ./src/./*~
	@/bin/rm -f *~
	@/bin/rm -f ./*~
	@/bin/rm -f *#
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="

re: fclean all
