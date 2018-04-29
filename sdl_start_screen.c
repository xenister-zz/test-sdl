/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_start_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:36:55 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/29 18:37:24 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_sdl.h"

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
    		printf("Erreur de chargement de l'image : %s\n",SDL_GetError());
    		return (0);
		}
		if ((sdlinfo->save = event_handler(sdlinfo)) > -1)
			return (sdlinfo->save);
    }
    return (0);
}

int		event_handler(t_sdl *sdlinfo)
{
	while (SDL_PollEvent(&(sdlinfo->event)))
    {
		SDL_Flip(MAINSCREEN);
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
	return (-2);
}