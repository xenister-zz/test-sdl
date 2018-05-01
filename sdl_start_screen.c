/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_start_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:36:55 by susivagn          #+#    #+#             */
/*   Updated: 2018/05/01 21:25:13 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

int			start_screen(t_sdl *sdlinfo)
{
	BKGROUND_POS.x = 0;
    BKGROUND_POS.y = 0;
	TITLES_POS.x = 73;
    TITLES_POS.y = 550;
	PRESS_POS.x = 293;
    PRESS_POS.y = 720;
	CREDIT_POS.x = 5;
    CREDIT_POS.y = 780;
	printf("-----IN START SCREEN-----\n");
    while ((event_handler(sdlinfo)) < 0)
    {
        SDL_WM_SetCaption("-- COREWAR --", NULL);
		if (!BKGROUND_SCREEN && (start_screen_set(sdlinfo) == -1))
		{
			printf("ERROR : Entry Screen Set\n");
			return (-1);
		}
		SDL_Flip(MAINSCREEN);
    }
    return (1);
}

int		title_screen(t_sdl *sdlinfo)
{
	TITLES_POS.y = 100;
	PRESS_POS.x = 293;
    PRESS_POS.y = 320;
	CREDIT_POS.x = 293;
    CREDIT_POS.y = 420;
	NAVI_POS.x = 250;
	NAVI_POS.y = 290;
	printf("-----IN TITLE SCREEN-----\n");
	while (((title_event_handler(sdlinfo)) < 0))
	{
		if (!BKGROUND_SCREEN && (title_screen_set(sdlinfo) == -1))
		{
			printf("ERROR : Title Screen Set\n");
			return (-1);
		}
		if (!NAVI)
			NAVI = IMG_Load("select.jpg");
		SDL_BlitSurface(NAVI, NULL, MAINSCREEN, &NAVI_POS);
		SDL_Flip(MAINSCREEN);
	}
	return (1);
}

int		title_screen_set(t_sdl *sdlinfo)
{
	BKGROUND_SCREEN = IMG_Load("bg_title.jpg");
	SDL_BlitSurface(BKGROUND_SCREEN, NULL, MAINSCREEN, &BKGROUND_POS);
	TITLE_SCREEN = IMG_Load("Corewar pix2.png");
	SDL_BlitSurface(TITLE_SCREEN, NULL, MAINSCREEN, &TITLES_POS);
	MEM_ZONE = TTF_RenderText_Blended(sdlinfo->police_start_screen,
		"BLOCK MODE", sdlinfo->pc_red);
	SDL_BlitSurface(MEM_ZONE, NULL, MAINSCREEN, &PRESS_POS);
	SDL_FreeSurface(MEM_ZONE);
	MEM_ZONE = TTF_RenderText_Blended(sdlinfo->police_start_screen,
		"TEXTE MODE", sdlinfo->pc_red);
	SDL_BlitSurface(MEM_ZONE, NULL, MAINSCREEN, &CREDIT_POS);
	SDL_FreeSurface(MEM_ZONE);
	CREDIT_POS.x = 360;
    CREDIT_POS.y = 620;
	MEM_ZONE = TTF_RenderText_Blended(sdlinfo->police_start_screen,
		"EXIT", sdlinfo->pc_red);
	SDL_BlitSurface(MEM_ZONE, NULL, MAINSCREEN, &CREDIT_POS);
	SDL_FreeSurface(MEM_ZONE);
	CREDIT_POS.x = 260;
    CREDIT_POS.y = 750;
	MEM_ZONE = TTF_RenderText_Blended(sdlinfo->police_game,
		"Glictevou, Upopee, Jrobin, Susivagn", sdlinfo->pc_red);
	SDL_BlitSurface(MEM_ZONE, NULL, MAINSCREEN, &CREDIT_POS);
	if ((BKGROUND_SCREEN == NULL) || (TITLE_SCREEN == NULL) || (MEM_ZONE == NULL))
    	return (-1);
	return(1);
}

int		start_screen_set(t_sdl *sdlinfo)
{
	BKGROUND_SCREEN = IMG_Load("FIST-iniere.jpg");
	SDL_BlitSurface(BKGROUND_SCREEN, NULL, MAINSCREEN, &BKGROUND_POS);
	TITLE_SCREEN = IMG_Load("Corewar pix2.png");
	SDL_BlitSurface(TITLE_SCREEN, NULL, MAINSCREEN, &TITLES_POS);
	MEM_ZONE = TTF_RenderText_Blended(sdlinfo->police_start_screen,
		"Press Space", sdlinfo->pc_red);
	SDL_BlitSurface(MEM_ZONE, NULL, MAINSCREEN, &PRESS_POS);
	if ((BKGROUND_SCREEN == NULL) || (TITLE_SCREEN == NULL) || (MEM_ZONE == NULL))
    	return (-1);
	return(1);
}

int		event_handler(t_sdl *sdlinfo)
{
	while (SDL_PollEvent(&(sdlinfo->event)))
    {
		SDL_Flip(MAINSCREEN);
		if (EVENT_TYPE == SDL_KEYDOWN)
    	{
			if (EVENT_KEY == SDLK_SPACE)
			{
				sdlinfo->save = 1;
				return (1);
			}
    	}
		else if (EVENT_TYPE == SDL_QUIT || EVENT_KEY == SDLK_ESCAPE)
		{
			sdlinfo->save = 0;
			SDL_FreeSurface(BKGROUND_SCREEN);
			SDL_FreeSurface(TITLE_SCREEN);
			SDL_FreeSurface(MEM_ZONE);
			return (0);
		}
	}
	return (-2);
}

int		title_event_handler(t_sdl *sdlinfo)
{
	int		key;
	while (SDL_PollEvent(&(sdlinfo->event)))
    {
		SDL_Flip(MAINSCREEN);
		if (EVENT_TYPE == SDL_KEYDOWN)
    	{
			if (EVENT_KEY == SDLK_DOWN || EVENT_KEY == SDLK_UP)
			{
				key = (EVENT_KEY == SDLK_DOWN) ? 1 : 2;
				navigation_key_handler(sdlinfo, key);
			}
			if (EVENT_KEY == SDLK_RETURN)
			{
				if (NAVI_POS.y == 490)
				{
					sdlinfo->save = 0;
					return (0);
				}
				GAMEMODE = (NAVI_POS.y == 290) ? 1 : 2;
				sdlinfo->save = 1;
				return (1);
			}
    	}
		else if (EVENT_TYPE == SDL_QUIT || EVENT_KEY == SDLK_ESCAPE)
		{
			sdlinfo->save = 0;
			SDL_FreeSurface(BKGROUND_SCREEN);
			SDL_FreeSurface(TITLE_SCREEN);
			SDL_FreeSurface(MEM_ZONE);
			return (0);
		}
	}
	return (-2);
}

void	navigation_key_handler(t_sdl *sdlinfo, int key)
{
	if (key == 1)
	{
		if (NAVI_POS.y != 490)
			NAVI_POS.y = NAVI_POS.y + 100;
		else
			NAVI_POS.y = 290;
	}
	else
	{
		if (NAVI_POS.y != 290)
			NAVI_POS.y = NAVI_POS.y - 100;
		else
			NAVI_POS.y = 490;
	}
}

void	test_pc_player(t_sdl *sdlinfo, int y)
{
	if (y <= 10)
		PLAYER = 1;
	else if (y >= 15 && y <= 25)
		PLAYER = 2;
	else if (y >= 30 && y <= 40)
		PLAYER = 3;
	else if (y >= 45 && y <= 55)
		PLAYER = 4;
	else
		PLAYER = 0;
	if ((sdlinfo->save % 5) == 0)
		sdlinfo->pc = 1;
	else
		sdlinfo->pc = 0;

}
