/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:04:17 by upopee            #+#    #+#             */
/*   Updated: 2018/04/19 14:27:46 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

// int		init_window(void)
// {
// 	uint32_t	win_flags;

// 	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
// 	{
// 		printf("Impossible d'initialiser SDL: %s\n", SDL_GetError());
// 		return (-1);
// 	}
// 	win_flags = SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF;
// 	SDL_SetVideoMode(640, 480, 32, win_flags);
// 	SDL_WM_SetCaption("Fenêtre de test", NULL);
// 	return (0);
// }

// void	main_loop(void)
// {
// 	SDL_Event	event;

// 	while (42)
// 	{
// 		SDL_WaitEvent(&event);
// 		if (event.type == SDL_QUIT)
// 			break;
// 	}
// }

// int		main(int argc, char* argv[])
// {
// 	if (init_window() == -1)
// 		return (EXIT_FAILURE);
// 	main_loop();
// 	SDL_Quit();
// 	return (EXIT_SUCCESS);
// }

SDL_Surface 	*load_image(char *filename);
void			apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);

int main( int argc, char *argv[ ] )
{
	uint32_t	win_flags;
	SDL_Event	event;
	const int	SCREEN_WIDTH = 640;
	const int	SCREEN_HEIGHT = 480;
	const int	SCREEN_BPP = 32;

	SDL_Surface *message = NULL;
	SDL_Surface *background = NULL;
	SDL_Surface *screen = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    {
        fprintf(stderr, "Can't init SDL: |%s|\n", SDL_GetError());
        return EXIT_FAILURE;
    }

	atexit( SDL_Quit ); 
	win_flags = SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF;

    if(!(screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, win_flags)))
    {
        printf("Can't set video mode: %s\n", SDL_GetError());
        return EXIT_FAILURE;
	}
	SDL_WM_SetCaption("La belle Fenetre !!!", NULL);

	while (42)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			break;
	}
	SDL_Quit();
    return EXIT_SUCCESS;
}

void	apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
	SDL_Rect	offset;

	offset.x = x;
	offset.y = y;

	//blitting de la surface
	SDL_BlitSurface(source, NULL, destination, &offset);
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