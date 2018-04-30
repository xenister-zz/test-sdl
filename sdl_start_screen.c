/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_start_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:36:55 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/30 21:13:43 by susivagn         ###   ########.fr       */
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
	printf("-----IN START SCREEN-----\n");
    while ((event_handler(sdlinfo)) < 0)
    {
        SDL_WM_SetCaption("-- COREWAR --", NULL);
		if (!BKGROUND_SCREEN)
		{
			BKGROUND_SCREEN = IMG_Load("FIST-iniere.jpg");
			SDL_BlitSurface(BKGROUND_SCREEN, NULL, MAINSCREEN, &BKGROUND_POS);
			TITLE_SCREEN = IMG_Load("Corewar pix2.png");
			SDL_BlitSurface(TITLE_SCREEN, NULL, MAINSCREEN, &TITLES_POS);
			MEM_ZONE = TTF_RenderText_Blended(sdlinfo->police_start_screen,
				"Press Space", sdlinfo->pc_red);
			SDL_BlitSurface(MEM_ZONE, NULL, MAINSCREEN, &PRESS_POS);
		}
		if ((BKGROUND_SCREEN == NULL) || (TITLE_SCREEN == NULL) || (MEM_ZONE == NULL))
    		return (0);
		SDL_Flip(MAINSCREEN);
    }
    return (1);
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
			return (0);
		}
	}
	return (-2);
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
