# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 15:28:26 by upopee            #+#    #+#              #
#    Updated: 2018/04/06 18:56:05 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		sdl_test
CC =		gcc
CFLAGS =	-I/Users/susivagn/homebrew/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
LFLAGS =	-L/Users/susivagn/homebrew/lib -lSDLmain -lSDL -Wl,-framework,Cocoa

FILE =		sdl.c

all:
	@$(CC) $(CFLAGS) $(LFLAGS) $(FILE) -o $(NAME)
	@printf "$(GREEN_B)✓$(EOC) $(YELLOW)$(NAME)$(EOC) : Binary created\n"

clean:
	@$(RM) $(NAME)
	@printf "$(RED_B)✗$(EOC) $(YELLOW)$(NAME)$(EOC) : Binary deleted\n"

YELLOW =	\e[31;33m
GREEN_B =	\e[32;1m
RED_B =		\e[31;1m
EOC =		\e[0m
