/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:31:03 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/30 21:13:18 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

int		init_sdl(t_sdl	*sdlinfo)
{
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
    return (1);
}

int		ttf_init(t_sdl *sdlinfo)
{
	sdlinfo->police_game = NULL;
	sdlinfo->police_start_screen = NULL;
	if (TTF_Init() == -1)
	{
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return (-1);
	}
	sdlinfo->police_game = TTF_OpenFont("vcrmono.ttf", 14);
	sdlinfo->police_start_screen = TTF_OpenFont("digitalix.ttf", 20);
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
