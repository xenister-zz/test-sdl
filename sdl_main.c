/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:28:22 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/30 21:21:27 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

int 			main(int argc, char *argv[])
{
    t_sdl *sdlinfo = malloc(sizeof(t_sdl));

	sdlinfo->save = 0;
	CUR_START = 0;
	CUR_END = MEM_SIZE;
	printf("-----start-----\n");
	if (init_sdl(sdlinfo) == 0)
	{
		printf("-----can't init-----\n");
		return (EXIT_FAILURE);
	}
	if (start_screen(sdlinfo) == 0)
	{
		printf("ERROR : Start Screen returned 0");
	}
	if (sdlinfo->save == 1 && sdl_clean(sdlinfo, 1))
	 	sdlinfo->save = main_screen(sdlinfo);
    SDL_Quit();
	TTF_CloseFont(sdlinfo->police_game);
	TTF_CloseFont(sdlinfo->police_start_screen);
	TTF_Quit();
	free(sdlinfo);
    return (EXIT_SUCCESS);
}

int		main_screen(t_sdl *sdlinfo)
{
	printf("---- IN MAIN SCREEN ----\n");
	sdlinfo->save = 0;
	GAMEMODE = 1;
	while ((event_handler(sdlinfo)) != 0)
	{
		if (main_screen_update(sdlinfo) == -1)
		{
			printf("MAIN SCREEN UPDATE RETURNED ERROR\n");
			return (-1);
		}
		SDL_Flip(MAINSCREEN);
	}
	return (-1);
}

int		main_screen_update(t_sdl *sdlinfo)
{
	SDL_Rect	memzone_pos;
	
	// y = (CUR_START / 64) | x = (CUR_START % 64)
	printf("---- IN MAIN SCREEN UPDATE ----\n");
	PLAYER = 0;
	while (CUR_START != CUR_END)
	{
		printf("X = %d ---- Y = %d", (CUR_START % 64), (CUR_START / 64));
		test_pc_player(sdlinfo, (CUR_START / 64));
		memzone_pos.x = (CUR_START % 64 == 0) ? 0 : (CUR_START % 64) * PIX_X;
		memzone_pos.y = (CUR_START / 64 == 0) ? 0 : (CUR_START / 64) * PIX_Y;
		if (update_gamemode1(sdlinfo) == -1)
			return (-1);
		if ((SDL_BlitSurface(MEM_ZONE, NULL, MAINSCREEN, &memzone_pos)) < 0)
		{
			printf("SDL_BlitSurface ERROR\n");
			return (-1);
		}
		SDL_FreeSurface(MEM_ZONE);
		CUR_START++;
		if ((CUR_START == MEM_SIZE) && (CUR_END != MEM_SIZE))
			CUR_START = 0;
	}
	return (1);
}

int		sdl_clean(t_sdl *sdlinfo, int resize)
{
	if (resize == 1)
		SDL_FreeSurface(MAINSCREEN);
	if (resize == 1 && (MAINSCREEN = SDL_SetVideoMode(WINDOW_BIGW, WINDOW_BIGH, BPP,
		SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
		printf("Impossible de changer MAINSCREEN : |%s|\n", SDL_GetError());
	SDL_FillRect(MAINSCREEN, NULL, SDL_MapRGB(MAINSCREEN->format, 0, 0, 0));
	SDL_Flip(MAINSCREEN);
	return (1);
}
