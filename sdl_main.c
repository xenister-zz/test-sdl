/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:28:22 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/19 18:17:16 by susivagn         ###   ########.fr       */
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
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, BPP, SDL_SWSURFACE);
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
    int continuer = 1;
    SDL_Event event;
    Uint32 fond = 0;
 
	printf("-----IN ACTU-----\n");
    while (continuer)
    {
        SDL_WM_SetCaption("TESTATOR SDL !", NULL);
        fond = SDL_MapRGB(screen->format, 228, 241, 254);
        SDL_FillRect(screen, NULL, fond);
		printf("-FOND-|%d|-\n", fond);
        SDL_Flip(screen);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}