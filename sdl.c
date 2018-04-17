/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:37:47 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/17 19:03:21 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
// #include <SDL.h>
// #include <SDL_image.h>

// SDL_Surface 	*load_image(char* filename);
// void			apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);

// int     main(int argc, char **argv)
// {
//     const int	SCREEN_WIDTH = 800;
// 	const int	SCREEN_HEIGHT = 600;
// 	const int	SCREEN_BPP = 32;

//     SDL_Event	event;

//     SDL_Surface *screen = NULL;
//     SDL_Surface *message = NULL;
// 	SDL_Surface *background = NULL;

//     //Initialisation de la SDL
//     if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
//         return (EXIT_FAILURE);
//     screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE);
//     if (screen == NULL)
//         return (EXIT_FAILURE);

//     //Blaze de la fenetre
//     SDL_WM_SetCaption(" La belle fenetre ! ", NULL);

//     //message = SDL_LoadBMP("circle.bmp");
//     //background = SDL_LoadBMP("clue.bmp");

//     //apply_surface(0, 0, background, screen);
//     //apply_surface(180, 140, message, screen);

//     SDL_MapRGB(screen->format, 0, 0, 0);

// 	if (SDL_Flip(screen) == -1)
// 	{
// 		printf("SDL NIKTAMER\n");
// 		return (EXIT_FAILURE);
// 	}

// 	while (42)
// 	{
// 		SDL_WaitEvent(&event);
// 		printf("NIKTAMER\n");
// 		if (event.type == SDL_QUIT)
// 		{
// 			//SDL_FreeSurface(message);
// 			//SDL_FreeSurface(background);
// 			break;
// 		}
// 	}

// 	// SDL_Delay(3000);

// 	// SDL_FreeSurface(message);
// 	// SDL_FreeSurface(background);

// 	return EXIT_SUCCESS;
// }

// SDL_Surface 	*load_image(char *filename)
// {
// 	SDL_Surface* loadedImage = NULL;
// 	SDL_Surface* optimizedImage = NULL;

// 	loadedImage = SDL_LoadBMP(filename);
// 	if(loadedImage != NULL)
// 	{
// 		optimizedImage = SDL_DisplayFormat(loadedImage);
// 		SDL_FreeSurface(loadedImage);
//     }
// 	return optimizedImage;
// }

// void	apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
// {
// 	SDL_Rect	offset;

// 	offset.x = x;
// 	offset.y = y;

// 	SDL_BlitSurface(source, NULL, destination, &offset);
// }

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc, char *argv[])
{
    SDL_Surface	*ecran = NULL; // Le pointeur qui va stocker la surface de l'écran
	SDL_Event 	event;
	char		*str;

    SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); // On tente d'ouvrir une fenêtre
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        printf("Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

	SDL_WM_SetCaption("SDL marche ou pas !", NULL);

	ecran = SDL_CreateRGBSurface(0, 640, 480, 32, 0, 0, 0, 0);

	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));

	SDL_Flip(ecran); /* Mise à jour de l'écran avec sa nouvelle couleur */
	int fbreak = 1;
    while (fbreak)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
			case SDL_QUIT:
				fbreak = 0;
                break ;
        }
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}