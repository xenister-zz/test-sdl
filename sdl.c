/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:37:47 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/10 19:49:04 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

SDL_Surface 	*load_image(char* filename);
void			apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);

int     main(int argc, char **argv)
{
    const int	SCREEN_WIDTH = 800;
	const int	SCREEN_HEIGHT = 600;
	const int	SCREEN_BPP = 32;

    SDL_Event	event;
    
    SDL_Surface *screen = NULL;
    SDL_Surface *message = NULL;
	SDL_Surface *background = NULL;

    //Initialisation de la SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return (EXIT_FAILURE);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE);
    if (screen == NULL)
        return (EXIT_FAILURE);
    
    //Blaze de la fenetre
    SDL_WM_SetCaption(" La belle fenetre ! ", NULL);

    //message = SDL_LoadBMP("circle.bmp");
    background = SDL_LoadBMP("clue.bmp");

    apply_surface(0, 0, background, screen);
    //apply_surface(180, 140, message, screen);

    if (SDL_Flip(screen) == -1)
        return (EXIT_FAILURE);

    while (42)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
        {
            SDL_FreeSurface(message);
            SDL_FreeSurface(background);
			break;
        }
	}

    // SDL_Delay(3000);

    // SDL_FreeSurface(message);
    // SDL_FreeSurface(background);

    return EXIT_SUCCESS;
}

SDL_Surface 	*load_image(char *filename)
{
	SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    
	loadedImage = SDL_LoadBMP(filename);
	if( loadedImage != NULL )
	{
		optimizedImage = SDL_DisplayFormat( loadedImage );
		SDL_FreeSurface( loadedImage );
    }
	return optimizedImage;
}

void	apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
	SDL_Rect	offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(source, NULL, destination, &offset);
}