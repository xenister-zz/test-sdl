# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 15:28:26 by upopee            #+#    #+#              #
#    Updated: 2018/04/30 15:25:37 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		sdl

CC =		gcc

SANITIZE =	-fsanitize=address

CFLAGS =	-I/Users/susivagn/homebrew/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
LFLAGS =	-L/Users/susivagn/homebrew/lib -lSDLmain -lSDL_image -lSDL_ttf -lSDL -Wl,-framework,Cocoa

CFLAGS2 =	-I/Users/susivagn/homebrew/include/SDL2 -D_THREAD_SAFE
LFLAGS2 =	-L/Users/susivagn/homebrew/lib -lSDL2

FILE =		sdl_main.c \
			sdl_gamemode.c \
			sdl_init.c \
			sdl_start_screen.c

FILE2 =		sdl2.c

all:
	@$(CC) -g $(SANITIZE) $(CFLAGS) $(LFLAGS) $(FILE) -o $(NAME)
	@printf "$(GREEN_B)✓$(EOC) $(YELLOW)$(NAME)$(EOC) : Binary created\n"

all2:
	@$(CC) $(CFLAGS2) $(LFLAGS2) $(FILE2) -o $(NAME)
	@printf "$(GREEN_B)✓$(EOC) $(YELLOW)$(NAME)$(EOC) : Binary created\n"

clean:
	@$(RM) $(NAME)
	@printf "$(RED_B)✗$(EOC) $(YELLOW)$(NAME)$(EOC) : Binary deleted\n"

re: clean all

YELLOW =	\e[31;33m
GREEN_B =	\e[32;1m
RED_B =		\e[31;1m
EOC =		\e[0m
