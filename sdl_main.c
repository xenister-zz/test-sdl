/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:28:22 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/29 18:41:34 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_sdl.h"

int 			main(int argc, char *argv[])
{
    t_sdl *sdlinfo = malloc(sizeof(t_sdl));
	int			boo = 0;
    
	printf("-----start-----\n");
	if (init_sdl(sdlinfo) == 0)
	{
		printf("-----can't init-----\n");
		return (EXIT_FAILURE);
	}
	boo = start_screen(sdlinfo);
	if (boo == 1 && sdl_clean(sdlinfo, 1))
	 	boo = main_screen(sdlinfo);
    SDL_Quit();
	TTF_CloseFont(sdlinfo->police);
	TTF_Quit();
    return (EXIT_SUCCESS);
}

int		ttf_init(t_sdl *sdlinfo)
{
	sdlinfo->police = NULL;
	if (TTF_Init() == -1)
	{
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return (-1);
	}
	sdlinfo->police = TTF_OpenFont("vcrmono.ttf", 14);
	init_ttf_color(sdlinfo);
	init_ttf_pc_color(sdlinfo);
	return (0);
}

void	init_ttf_color(t_sdl *sdlinfo)
{
	sdlinfo->black.r = 0;
	sdlinfo->black.g = 0;
	sdlinfo->black.b = 0;
	sdlinfo->white.r = 255;
	sdlinfo->white.g = 255;
	sdlinfo->white.b = 255;
	sdlinfo->red.r = 255;
	sdlinfo->red.g = 80;
	sdlinfo->red.b = 80;
	sdlinfo->blue.r = 0;
	sdlinfo->blue.g = 204;
	sdlinfo->blue.b = 255;
	sdlinfo->green.r = 0;
	sdlinfo->green.g = 255;
	sdlinfo->green.b = 0;
	sdlinfo->yellow.r = 255;
	sdlinfo->yellow.g = 255;
	sdlinfo->yellow.b = 153;
	sdlinfo->grey.r = 165;
	sdlinfo->grey.g = 165;
	sdlinfo->grey.b = 192;
}

void	init_ttf_pc_color(t_sdl *sdlinfo)
{
	sdlinfo->pc_red.r = 204;
	sdlinfo->pc_red.g = 0;
	sdlinfo->pc_red.b = 0;
	sdlinfo->pc_blue.r = 51;
	sdlinfo->pc_blue.g = 102;
	sdlinfo->pc_blue.b = 255;
	sdlinfo->pc_green.r = 0;
	sdlinfo->pc_green.g = 204;
	sdlinfo->pc_green.b = 0;
	sdlinfo->pc_yellow.r = 255;
	sdlinfo->pc_yellow.g = 255;
	sdlinfo->pc_yellow.b = 0;
}

int		main_screen(t_sdl *sdlinfo)
{
	printf("---- IN MAIN SCREEN ----\n");
	sdlinfo->save = 0;
	GAMEMODE = 2;
	while ((event_handler(sdlinfo)) != 0)
	{
		if (main_screen_update(sdlinfo) == -1)
		{
			printf("MAIN SCREEN UPDATE RETURNED ERROR\n");
			return (-1);
		}
		if (sdlinfo->save == 10000)
			sdlinfo->save = 0;
		sdlinfo->save++;
		SDL_Flip(MAINSCREEN);
	}
	return (-1);
}

int		main_screen_update(t_sdl *sdlinfo)
{
	int			x;
	int			y;
	int			pc;
	SDL_Rect	memzone_pos;

	printf("---- IN MAIN SCREEN UPDATE ----\n");
	x = 0;
	y = 0;
	pc = 0;
	PLAYER = 0;
	while (y < 64)
	{
		printf("X = %d ---- Y = %d", x, y);
		test_pc_player(sdlinfo, y);
		memzone_pos.x = (x == 0) ? 0 : x * 20;
		memzone_pos.y = (y == 0) ? 0 : y * 18;
		if (memory_update(sdlinfo) == -1)
			return (-1);
		if ((SDL_BlitSurface(MEM_ZONE, NULL, MAINSCREEN, &memzone_pos)) < 0)
		{
			printf("SDL_BlitSurface ERROR\n");
			return (-1);
		}
		SDL_FreeSurface(MEM_ZONE);
		x++;
		if (x == 64 && (y = y + 1))
			x = 0;
	}
	return (1);
}

void	test_pc_player(t_sdl *sdlinfo, int y)
{
	if (y <= 10)
		PLAYER = 1;
	else if (y >= 15 && y <= 25 )
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

int		memory_update(t_sdl *sdlinfo)
{
	printf("---- IN MEMORY UPDATE ----\n");
	if (GAMEMODE == 1)
	{
		get_txt_color(sdlinfo);
		if (PLAYER > 0)
		MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police, "01", sdlinfo->txt_color, sdlinfo->bg_color);
		else
		MEM_ZONE = TTF_RenderText_Solid(sdlinfo->police, "00", sdlinfo->grey);
	}
	else
	{
		get_block_color(sdlinfo);
		if (PLAYER > 0)
		MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police, "  ", sdlinfo->txt_color, sdlinfo->bg_color);
		else
		MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police, "  ", sdlinfo->txt_color, sdlinfo->grey);
	}
	printf("TFF EXIT\n");
	if (MEM_ZONE == NULL)
	{
		printf("ERROR: Memory TTF_Render\n");
		return (-1);
	}
	return (1);
}

void	get_block_color(t_sdl *sdlinfo)
{
	printf("++++ In Block Color ++++\n");
	if (sdlinfo->pc == 0)
	{
		if (PLAYER == 1)
			sdlinfo->bg_color = sdlinfo->pc_red;
		else if (PLAYER == 2)
			sdlinfo->bg_color = sdlinfo->pc_blue;
		else if (PLAYER == 3)
			sdlinfo->bg_color = sdlinfo->pc_green;
		else if (PLAYER == 4)
			sdlinfo->bg_color = sdlinfo->pc_yellow;
	}
	else
	{
		if (PLAYER == 1)
			sdlinfo->bg_color = sdlinfo->red;
		else if (PLAYER == 2)
			sdlinfo->bg_color = sdlinfo->blue;
		else if (PLAYER == 3)
			sdlinfo->bg_color = sdlinfo->green;
		if (PLAYER == 4)
			sdlinfo->bg_color = sdlinfo->yellow;
	}
	printf("++++ END Block Color ++++\n");
}

void	get_txt_color(t_sdl *sdlinfo)
{
	printf("++++ In Get Texte Color ++++\n");
	if (sdlinfo->pc == 0)
	{
		sdlinfo->bg_color = sdlinfo->black;
		if (PLAYER == 1)
			sdlinfo->txt_color = sdlinfo->red;
		else if (PLAYER == 2)
			sdlinfo->txt_color = sdlinfo->blue;
		else if (PLAYER == 3)
			sdlinfo->txt_color = sdlinfo->green;
		else if (PLAYER == 4)
			sdlinfo->txt_color = sdlinfo->yellow;
	}
	else
	{
		sdlinfo->txt_color = sdlinfo->black;
		if (PLAYER == 1)
			sdlinfo->bg_color = sdlinfo->red;
		else if (PLAYER == 2)
			sdlinfo->bg_color = sdlinfo->blue;
		else if (PLAYER == 3)
			sdlinfo->bg_color = sdlinfo->green;
		if (PLAYER == 4)
			sdlinfo->bg_color = sdlinfo->yellow;
	}
	printf("++++ END Texte Color ++++\n");
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

int		init_sdl(t_sdl	*sdlinfo)
{
	//printf("-----IN INIT-----\n");
	BKGROUND_SCREEN = NULL;
	TITLE_SCREEN = NULL;
	MAINSCREEN = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        printf("Erreur d'initialisation de la SDL");
        return (0);
    }
    MAINSCREEN = SDL_SetVideoMode(WINDOW_W, WINDOW_H, BPP,
		 SDL_HWSURFACE | SDL_RESIZABLE);
    if (MAINSCREEN == NULL)
    {
        printf("Impossible de charger le mode vidéo : |%s|\n", SDL_GetError());
        return (0);
    }
	if (ttf_init(sdlinfo) == -1)
	{
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return (-1);
	}
	//printf("-----EXIT INIT-----\n");
    return (1);
}

int			start_screen(t_sdl *sdlinfo)
{
	printf("-----POS AFFECTING SCREEN-----\n");

	BKGROUND_POS.x = 0;
    BKGROUND_POS.y = 0;
	TITLES_POS.x = 73;
    TITLES_POS.y = 550;
	sdlinfo->continuer = 1;
	printf("-----IN START SCREEN-----\n");
    while (sdlinfo->continuer)
    {
        SDL_WM_SetCaption("-- COREWAR --", NULL);
		if (!BKGROUND_SCREEN)
		{
			BKGROUND_SCREEN = IMG_Load("FIST-iniere.jpg");
			SDL_BlitSurface(BKGROUND_SCREEN, NULL, MAINSCREEN, &BKGROUND_POS);
			TITLE_SCREEN = IMG_Load("Corewar pix2.png");
			SDL_BlitSurface(TITLE_SCREEN, NULL, MAINSCREEN, &TITLES_POS);
		}
		if ((BKGROUND_SCREEN == NULL) || (TITLE_SCREEN == NULL))
		{
    		printf("Erreur de chargement de l'image : %s\n",SDL_GetError());
    		return (0);
		}
		if ((sdlinfo->save = event_handler(sdlinfo)) > -1)
			return (sdlinfo->save);
    }
    return (0);
}

int		event_handler(t_sdl *sdlinfo)
{
	while (SDL_PollEvent(&(sdlinfo->event)))
    {
		SDL_Flip(MAINSCREEN);
		if (EVENT_TYPE == SDL_KEYDOWN)
    	{
			if (EVENT_KEY == SDLK_SPACE)
				return (1);
    	}
		else if (EVENT_TYPE == SDL_QUIT || EVENT_KEY == SDLK_ESCAPE)
		{
			SDL_FreeSurface(BKGROUND_SCREEN);
			SDL_FreeSurface(TITLE_SCREEN);
			return (0);
		}
	}
	return (-2);
}