/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:10:59 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/30 21:20:21 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MY_SDL_H_
# define _MY_SDL_H_

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>

# define MEM_SIZE 4096
# define PIX_X 20
# define PIX_Y 18
# define WINDOW_W 800
# define WINDOW_BIGW 1285
# define WINDOW_H 800
# define WINDOW_BIGH 1160
# define BPP 32
# define GAMEMODE sdlinfo->game_mode
# define PLAYER sdlinfo->player
# define MAINSCREEN sdlinfo->screen
# define MEM_ZONE sdlinfo->mem_zone
# define EVENT_TYPE sdlinfo->event.type
# define EVENT_KEY sdlinfo->event.key.keysym.sym
# define BKGROUND_POS sdlinfo->background_pos
# define TITLES_POS sdlinfo->title_pos
# define PRESS_POS sdlinfo->press_pos
# define MAIN_POS sdlinfo->main_pos
# define BKGROUND_SCREEN sdlinfo->background
# define TITLE_SCREEN sdlinfo->title
# define CUR_START sdlinfo->cursor_start
# define CUR_END sdlinfo->cursor_end


typedef struct      s_sdl
{
	int				game_mode;
	int				player;
	int				pc;
	int				write;
	int				cursor_end;
	int				cursor_start;
    SDL_Surface		*screen;
	SDL_Surface		*background;
	SDL_Surface		*title;
	SDL_Surface		*mem_zone;
	SDL_Event		event;
    SDL_Rect		main_pos;
	SDL_Rect		title_pos;
	SDL_Rect		press_pos;
	SDL_Rect		background_pos;
	TTF_Font		*police_game;
	TTF_Font		*police_start_screen;
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
int			main_screen_update(t_sdl *sdlinfo);
int			ttf_init(t_sdl *sdlinfo);
void		init_ttf_color(t_sdl *sdlinfo);
void		init_ttf_pc_color(t_sdl *sdlinfo);
int			sdl_clean(t_sdl *sdlinfo, int resize);
int			start_screen(t_sdl *sdlinfo);
int			init_sdl(t_sdl *sdlinfo);
int			event_handler(t_sdl *sdlinfo);
int			update_gamemode1(t_sdl *sdlinfo);
int			update_gamemode2(t_sdl *sdlinfo);
void		get_block_color(t_sdl *sdlinfo);
void		get_txt_color(t_sdl *sdlinfo);
void		test_pc_player(t_sdl *sdlinfo, int y);
void		get_wrt_txt_color(t_sdl *sdlinfo);

#endif