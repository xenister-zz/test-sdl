/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:28:22 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/19 22:11:42 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_sdl.h"

int 			main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL;
    
	printf("-----start-----\n");
    if ((screen = init_sdl(screen)) == NULL)
	{
		printf("-----can't init-----\n");
		return (EXIT_FAILURE);
    }
    actu(screen);

    SDL_Quit();
    return EXIT_SUCCESS;
}

SDL_Surface		*init_sdl(SDL_Surface *screen)
{
    const int	SCREEN_W = WINDOW_W;
	const int	SCREEN_H = WINDOW_H;
	const int	BPP = COLOR_DEPTH;

	printf("-----IN INIT-----\n");
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        printf("Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
    }
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, BPP, SDL_HWSURFACE);
    if (screen == NULL)
    {
        printf("Impossible de charger le mode vidéo : |%s|\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
	printf("-----EXIT INIT-----\n");
    return (screen);
}

void			actu(SDL_Surface *screen)
{
	SDL_Surface		*background = NULL, *title = NULL;
    int 			continuer = 1;
    SDL_Event 		event;
	SDL_Rect		positionbg, positiontitle;
    //Uint32 			fond = 0;
	
	positionbg.x = 0;
    positionbg.y = 0;
	positiontitle.x = 50;
    positiontitle.y = 400;
 
	printf("-----IN ACTU-----\n");
    while (continuer)
    {
        SDL_WM_SetCaption("TESTATOR SDL !", NULL);
		if (!background)
		{
			background = IMG_Load("FIST-iniere.jpg");
			SDL_BlitSurface(background, NULL, screen, &positionbg);
			title = IMG_Load("fistwars.png");
			SDL_BlitSurface(title, NULL, screen, &positiontitle);
		}
		// if (!title)
		// {
			
		// }
		if ((background == NULL) || (title == NULL))
		{
    		printf("Erreur de chargement de l'image : %s",SDL_GetError());
    		return ;
		}
        //fond = SDL_MapRGB(screen->format, 228, 241, 254);
        //SDL_FillRect(screen, NULL, fond);
		//printf("-FOND-|%d|-\n", fond);
		
        SDL_Flip(screen);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
			{
				SDL_FreeSurface(background);
				SDL_FreeSurface(title);
				continuer = 0;
			}
        }
    }
}