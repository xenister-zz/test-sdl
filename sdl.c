/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:37:47 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/06 19:08:14 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

SDL_Surface 	*load_image(char *filename);
void			apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);

int     main(int argc, char **argv)
{
    const int	SCREEN_WIDTH = 640;
	const int	SCREEN_HEIGHT = 480;
	const int	SCREEN_BPP = 32;

    SDL_Event	event;
    
    SDL_Surface *screen = NULL;
    SDL_Surface *message = NULL;
	SDL_Surface *background = NULL;

    //Initialisation de la SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return (EXIT_FAILURE);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
        return (EXIT_FAILURE);
    
    //Blaze de la fenetre
    SDL_WM_SetCaption(" La belle et la fenetre ! ", NULL);

    //Chargement des image et application sur screen
    message = load_image("circle.bmp");
    background = load_image("clue.bmp");

    apply_surface(0, 0, background, screen);
    //apply_surface(180, 140, message, screen);

    //mise a jour de screen
    if (SDL_Flip(screen) == -1)
        return (EXIT_FAILURE);

    // while (42)
	// {
	// 	SDL_WaitEvent(&event);
	// 	if (event.type == SDL_QUIT)
    //     {
    //         // on libere la memoire avant de quit
    //         SDL_FreeSurface(message);
    //         SDL_FreeSurface(background);  
	// 		break;
    //     }
	// }

    SDL_Delay(3000);

    SDL_FreeSurface(message);
    SDL_FreeSurface(background); 

    return EXIT_SUCCESS;
}

SDL_Surface 	*load_image(char *filename)
{
	//Surface tampon qui nous servira pour charger l'image
	SDL_Surface* loadedImage = NULL;

	//L'image optimisée qu'on va utiliser
	SDL_Surface* optimizedImage = NULL;

	//Chargement de l'image
	loadedImage = SDL_LoadBMP(filename);

	//Si le chargement se passe bien
	if( loadedImage != NULL )
	{
		//Création de l'image optimisée
		optimizedImage = SDL_DisplayFormat( loadedImage );

		//Libération de l'ancienne imag
		SDL_FreeSurface( loadedImage );
	}

	//On retourne l'image optimisée
	return optimizedImage;
}

void	apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
	SDL_Rect	offset;

	offset.x = x;
	offset.y = y;

	//blitting de la surface
	SDL_BlitSurface(source, NULL, destination, &offset);
}