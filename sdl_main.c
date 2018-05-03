/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:28:22 by susivagn          #+#    #+#             */
/*   Updated: 2018/05/03 06:09:06 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"


/*	fonction init juska title screen : start_sdl(struct sdl)
	Fonction actu de la main screen : main_screen(struct sdl)
	Fonction pour set les flags de couleur : get_data.c
*/

static int	quit_sdl(t_sdl *sdlinfo)
{
	SDL_FreeSurface(sdlinfo->screen);
	SDL_Quit();
	TTF_CloseFont(sdlinfo->police_game);
	TTF_CloseFont(sdlinfo->police_start_screen);
	TTF_Quit();
	return (-1)
}

int		main(int argc, char *argv[])
{
	
	if (start_sdl(&sdlinfo) == -1)
	{
		return (quit_sdl(sdlinfo));
	}
	if (sdlinfo.save == 1 && sdl_clean(&sdlinfo, 1, 0))

	/* Fonction to call */
	main_screen(&sdlinfo)

	printf("SORTIE WHILE PRINCIPALE\n");
	SDL_FreeSurface(sdlinfo.screen);
	sdl_ttf_quit(&sdlinfo);
	return (1);
}

int		start_sdl(t_sdl *sdlinfo)
{
	t_sdl	sdlinfo;
	if (init_sdl(&sdlinfo) == -1)
	{
		printf("-----can't init-----\n");
		return (-1);
	}
	if (start_screen(sdlinfo) == -1)
		return (-1);
	if (sdlinfo->save == 1 && sdl_clean(sdlinfo, 0, 1))
		title_screen(&sdlinfo);
	if (sdlinfo->save == 0)
		return (-1);
}

int		main_screen(t_sdl *sdlinfo)
{
	printf("---- IN MAIN SCREEN ----\n");
	sdlinfo->save = 2;
	if ((event_handler(sdlinfo)) != 0)
	{
		if (main_screen_update(sdlinfo) == -1)
		{
			printf("MAIN SCREEN UPDATE RETURNED ERROR\n");
			return (0);
		}
		SDL_Flip(MAINSCREEN);
	}
	if (sdlinfo->save == 0)
		return (0);
	return (-1);
}

int		main_screen_update(t_sdl *sdlinfo)
{
	SDL_Rect	memzone_pos;

	printf("---- IN MAIN SCREEN UPDATE ----\n");
	PLAYER = 1;
	while (CUR_X != CUR_Y)
	{
		printf("X = %d ---- Y = %d", (CUR_X & 63), (CUR_X / 64));
		test_pc_player(sdlinfo, (CUR_X / 64));
		memzone_pos.x = ((CUR_X & 63) == 0) ? 0 : (CUR_X & 63) * PIX_X;
		memzone_pos.y = (CUR_X / 64 == 0) ? 0 : (CUR_X / 64) * PIX_Y;
		if (update_gamemode1(sdlinfo) == -1)
			return (-1);
		if ((SDL_BlitSurface(MEM_ZONE, NULL, MAINSCREEN, &memzone_pos)) < 0)
		{
			printf("SDL_BlitSurface ERROR\n");
			return (-1);
		}
		SDL_FreeSurface(MEM_ZONE);
		CUR_X++;
		if ((CUR_X == MEM_SIZE) && (CUR_Y != MEM_SIZE))
			CUR_X = 0;
	}
	printf("SORTIE MAIN SCREEN UPDATE\n");
	return (1);
}

int		sdl_clean(t_sdl *sdlinfo, int resize, int surface_free)
{
	if (resize == 1)
		SDL_FreeSurface(MAINSCREEN);
	if (resize == 1 && (MAINSCREEN = SDL_SetVideoMode(WINDOW_BIGW,
		WINDOW_BIGH, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
		printf("Impossible de changer MAINSCREEN : |%s|\n", SDL_GetError());
	SDL_FillRect(MAINSCREEN, NULL, SDL_MapRGB(MAINSCREEN->format, 0, 0, 0));
	SDL_Flip(MAINSCREEN);
	if (surface_free == 1)
		sdl_free(BKGROUND_SCREEN, TITLE_SCREEN, MEM_ZONE);
	return (1);
}

int		sdl_free(SDL_Surface *tofree1, SDL_Surface *tofree2,
		SDL_Surface *tofree3)
{
	if (tofree1 != NULL)
		SDL_FreeSurface(tofree1);
	if (tofree2 != NULL)
		SDL_FreeSurface(tofree2);
	if (tofree3 != NULL)
		SDL_FreeSurface(tofree3);
	tofree1 = NULL;
	tofree2 = NULL;
	tofree3 = NULL;
	return (1);
}
