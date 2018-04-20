/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:28:22 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/20 20:09:47 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_sdl.h"

int 			main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL;
	int			boo = 0;
    
	printf("-----start-----\n");
	if ((screen = init_sdl(screen)) == NULL)
	{
		printf("-----can't init-----\n");
		return (EXIT_FAILURE);
	}
	boo = start_screen(screen);
	if (boo == 1)
		boo = main_screen(screen);

    SDL_Quit();
    return (EXIT_SUCCESS);
}

SDL_Surface		*init_sdl(SDL_Surface *screen)
{
	//printf("-----IN INIT-----\n");
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        //printf("Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
    }
    screen = SDL_SetVideoMode(WINDOW_W, WINDOW_H, BPP, SDL_HWSURFACE | SDL_RESIZABLE);
    if (screen == NULL)
    {
        //printf("Impossible de charger le mode vidéo : |%s|\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
	//printf("-----EXIT INIT-----\n");
    return (screen);
}

int			start_screen(SDL_Surface *screen)
{
	SDL_Surface		*background = NULL, *title = NULL;
    int 			continuer = 1;
    SDL_Event 		event;
	SDL_Rect		positionbg, positiontitle;
	
	positionbg.x = 0;
    positionbg.y = 0;
	positiontitle.x = 73;
    positiontitle.y = 550;
 
	printf("-----IN START SCREEN-----\n");
    while (continuer)
    {
        SDL_WM_SetCaption("-- SDL TESTINATATOR --", NULL);
		if (!background)
		{
			background = IMG_Load("FIST-iniere.jpg");
			SDL_BlitSurface(background, NULL, screen, &positionbg);
			title = IMG_Load("Corewar pix2.png");
			SDL_BlitSurface(title, NULL, screen, &positiontitle);
		}
		if ((background == NULL) || (title == NULL))
		{
    		printf("Erreur de chargement de l'image : %s",SDL_GetError());
    		return (0);
		}
        SDL_Flip(screen);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
			{
				SDL_FreeSurface(background);
				SDL_FreeSurface(title);
				return (0);
			}
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						return (0);
					case SDLK_SPACE || SDLK_RETURN:
						return (1);
				}
				break;
			//case default:
				//continuer = 1;
        }
    }
    return (0);
}