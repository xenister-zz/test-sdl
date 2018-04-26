/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:28:22 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/26 19:24:20 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_sdl.h"

int 			main(int argc, char *argv[])
{
    t_sdl *sdlinfo = malloc(sizeof(t_sdl));
	int			boo = 0;
    
	printf("-----start-----\n");
	if (init_sdl(sdlinfo) == 0)
	{
		printf("-----can't init-----\n");
		return (EXIT_FAILURE);
	}
	boo = start_screen(sdlinfo);
	if (boo == 1 && sdl_clean(sdlinfo, 1))
	 	boo = main_screen(sdlinfo);
    SDL_Quit();
	// TTF_CloseFont(police);
	// TTF_Quit();
    return (EXIT_SUCCESS);
}

int		ttf_init(t_sdl *sdlinfo)
{
	sdlinfo->police = NULL;
	if (TTF_Init() == -1)
	{
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return (-1);
	}
	sdlinfo->police = TTF_OpenFont("digitalix.ttf", 65);
	init_ttf_color(sdlinfo);
	return (0);
}

void	init_ttf_color(t_sdl *sdlinfo)
{
	sdlinfo->black.r = 0;
	sdlinfo->black.g = 0;
	sdlinfo->black.b = 0;
	sdlinfo->white.r = 255;
	sdlinfo->white.g = 255;
	sdlinfo->white.b = 255;
	sdlinfo->red.r = 255;
	sdlinfo->red.g = 51;
	sdlinfo->red.b = 0;
	sdlinfo->blue.r = 51;
	sdlinfo->blue.g = 102;
	sdlinfo->blue.b = 255;
	sdlinfo->green.r = 102;
	sdlinfo->green.g = 255;
	sdlinfo->green.b = 102;
}

int		main_screen(t_sdl *sdlinfo)
{
	while (sdlinfo->continuer)
	{
		if ((sdlinfo->save = event_handler(sdlinfo)) < 1)
			return (sdlinfo->save);
	}
	return (-1);
}

int		sdl_clean(t_sdl *sdlinfo, int resize)
{
	if (resize == 1)
		SDL_FreeSurface(MAINSCREEN);
	if (resize == 1 && (MAINSCREEN = SDL_SetVideoMode(WINDOW_BIGW, WINDOW_H, BPP, 
		SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
		printf("Impossible de changer MAINSCREEN : |%s|\n", SDL_GetError());
	SDL_FillRect(MAINSCREEN, NULL, SDL_MapRGB(MAINSCREEN->format, 125, 0, 0));
	SDL_Flip(MAINSCREEN);
	return (1);
}

int		init_sdl(t_sdl	*sdlinfo)
{
	//printf("-----IN INIT-----\n");
	BKGROUND_SCREEN = NULL;
	TITLE_SCREEN = NULL;
	MAINSCREEN = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        //printf("Erreur d'initialisation de la SDL");
        return (0);
    }
    MAINSCREEN = SDL_SetVideoMode(WINDOW_W, WINDOW_H, BPP,
		 SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    if (MAINSCREEN == NULL)
    {
        //printf("Impossible de charger le mode vidéo : |%s|\n", SDL_GetError());
        return (0);
    }
	if (ttf_init(sdlinfo) == -1)
	{
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return (-1);
	}
	//printf("-----EXIT INIT-----\n");
    return (1);
}

int			start_screen(t_sdl *sdlinfo)
{
	printf("-----POS AFFECTING SCREEN-----\n");

	BKGROUND_POS.x = 0;
    BKGROUND_POS.y = 0;
	TITLES_POS.x = 73;
    TITLES_POS.y = 550;
	sdlinfo->continuer = 1;
	printf("-----IN START SCREEN-----\n");
    while (sdlinfo->continuer)
    {
        SDL_WM_SetCaption("-- COREWAR --", NULL);
		if (!BKGROUND_SCREEN)
		{
			BKGROUND_SCREEN = IMG_Load("FIST-iniere.jpg");
			SDL_BlitSurface(BKGROUND_SCREEN, NULL, MAINSCREEN, &BKGROUND_POS);
			TITLE_SCREEN = IMG_Load("Corewar pix2.png");
			SDL_BlitSurface(TITLE_SCREEN, NULL, MAINSCREEN, &TITLES_POS);
		}
		if ((BKGROUND_SCREEN == NULL) || (TITLE_SCREEN == NULL))
		{
    		printf("Erreur de chargement de l'image : %s",SDL_GetError());
    		return (0);
		}
		if ((sdlinfo->save = event_handler(sdlinfo)) > -1)
			return (sdlinfo->save);
    }
    return (0);
}

int		event_handler(t_sdl *sdlinfo)
{
	while (sdlinfo->continuer)
    {
		SDL_Flip(MAINSCREEN);
		SDL_WaitEvent(&sdlinfo->event);
		if (EVENT_TYPE == SDL_KEYDOWN)
    	{
			if (EVENT_KEY == SDLK_SPACE)
				return (1);
    	}
		else if (EVENT_TYPE == SDL_QUIT || EVENT_KEY == SDLK_ESCAPE)
		{
			SDL_FreeSurface(BKGROUND_SCREEN);
			SDL_FreeSurface(TITLE_SCREEN);
			return (0);
		}
	}
	return (-1);
}