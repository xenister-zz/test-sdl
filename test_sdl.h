/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:10:59 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/26 19:26:31 by susivagn         ###   ########.fr       */
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

# define WINDOW_W 800
# define WINDOW_BIGW 1400
# define WINDOW_H 800
# define BPP 32
# define MAINSCREEN sdlinfo->screen
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
    SDL_Surface		*screen;
	SDL_Surface		*background;
	SDL_Surface		*title;
	SDL_Event		event;
    SDL_Rect		main_pos;
	SDL_Rect		title_pos;
	SDL_Rect		background_pos;
	TTF_Font		*police;
	SDL_Color		black;
	SDL_Color		white;
	SDL_Color		red;
	SDL_Color		blue;
	SDL_Color		green;
	int				save;
}                   t_sdl;

int			main_screen(t_sdl *sdlinfo);
void		init_ttf_color(t_sdl *sdlinfo);
int			sdl_clean(t_sdl *sdlinfo, int resize);
int			start_screen(t_sdl *sdlinfo);
int			init_sdl(t_sdl *sdlinfo);
int			event_handler(t_sdl *sdlinfo);

#endif