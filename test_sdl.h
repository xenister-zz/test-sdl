/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:10:59 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/29 18:30:01 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TEST_SDL_H_
# define _TEST_SDL_H_

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>

# define MEM_SIZE 4096
# define WINDOW_W 800
# define WINDOW_BIGW 1600
# define WINDOW_H 800
# define WINDOW_BIGH 1200
# define BPP 32
# define GAMEMODE sdlinfo->game_mode
# define PLAYER sdlinfo->player
# define MAINSCREEN sdlinfo->screen
# define MEM_ZONE sdlinfo->mem_zone
# define EVENT_TYPE sdlinfo->event.type
# define EVENT_KEY sdlinfo->event.key.keysym.sym
# define BKGROUND_POS sdlinfo->background_pos
# define TITLES_POS sdlinfo->title_pos
# define MAIN_POS sdlinfo->main_pos
# define BKGROUND_SCREEN sdlinfo->background
# define TITLE_SCREEN sdlinfo->title

typedef struct      s_sdl
{
    int             continuer;
	int				game_mode;
	int				player;
	int				pc;
    SDL_Surface		*screen;
	SDL_Surface		*background;
	SDL_Surface		*title;
	SDL_Surface		*mem_zone;
	SDL_Event		event;
    SDL_Rect		main_pos;
	SDL_Rect		title_pos;
	SDL_Rect		background_pos;
	TTF_Font		*police;
	SDL_Color		txt_color;
	SDL_Color		bg_color;
	SDL_Color		black;
	SDL_Color		white;
	SDL_Color		red;
	SDL_Color		pc_red;
	SDL_Color		blue;
	SDL_Color		pc_blue;
	SDL_Color		green;
	SDL_Color		pc_green;
	SDL_Color		yellow;
	SDL_Color		pc_yellow;
	SDL_Color		grey;
	int				save;
}                   t_sdl;

int			main_screen(t_sdl *sdlinfo);
void		init_ttf_color(t_sdl *sdlinfo);
void		init_ttf_pc_color(t_sdl *sdlinfo);
int			sdl_clean(t_sdl *sdlinfo, int resize);
int			start_screen(t_sdl *sdlinfo);
int			init_sdl(t_sdl *sdlinfo);
int			event_handler(t_sdl *sdlinfo);
int			memory_update(t_sdl *sdlinfo);
int			main_screen_update(t_sdl *sdlinfo);
void		get_block_color(t_sdl *sdlinfo);
void		get_txt_color(t_sdl *sdlinfo);
void		test_pc_player(t_sdl *sdlinfo, int y);

#endif